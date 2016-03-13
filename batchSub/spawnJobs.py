import os
import subprocess
from optparse import OptionParser

parser = OptionParser()
parser.add_option("-s", "--sample", dest="sample", default="znunu_0_600",
                  help="sample to analyze")
parser.add_option("-n", "--name", dest="name", default="",
                  help="name for condor files")
parser.add_option("-e", "--exec", dest="executable", default="baselinePlots",
                  help="name for condor files")

(options, args) = parser.parse_args()

if options.name == "" : options.name = options.sample

##########################
# archive repos for copying
# to worker nodes
##########################
os.system("cd ../ ; rm GMSBstudies.tar ; git archive master -o GMSBstudies.tar")
os.system("cd ../../AnalysisTools ; rm AnalysisTools.tar ; git archive master -o AnalysisTools.tar")

commitHash = subprocess.check_output("cd ../ ; git rev-parse HEAD",shell=True)

#os.system('eos root://cmseos.fnal.gov mkdir /eos/uscms/store/user/awhitbe1/GMSBstudies/{0}'.format(options.executable))
#os.system("test=`eos root://cmseos.fnal.gov ls /eos/uscms/store/user/awhitbe1/GMSBstudies/{0} | grep 'No such file or directory'` ; if [ $test == '' ] ; then ;  eos root://cmseos.fnal.gov mkdir /eos/uscms/store/user/awhitbe1/GMSBstudies/{0} ; fi".format(options.executable))

#os.system('eos root://cmseos.fnal.gov mkdir /eos/uscms/store/user/awhitbe1/GMSBstudies/{0}/{1}'.format(options.executable,commitHash))
#os.system("test=`eos root://cmseos.fnal.gov ls /eos/uscms/store/user/awhitbe1/GMSBstudies/{0}/{1} | grep 'No such file or directory'` ; if [ $test == '' ] ; then ; eos root://cmseos.fnal.gov mkdir /eos/uscms/store/user/awhitbe1/GMSBstudies/{0}/{1} ; fi".format(options.executable,commitHash))

jdlFile = """universe = vanilla
Executable = worker.sh
Requirements = OpSys == "LINUX" && (Arch != "DUMMY" )
request_disk = 10000000
request_memory = 10000
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT_OR_EVICT
Transfer_Input_Files = ../GMSBstudies.tar, ../../AnalysisTools/AnalysisTools.tar
PeriodicRemove = ( JobStatus == 2 ) && ( ( CurrentTime - EnteredCurrentStatus ) > 600 )
Output = {0}_{1}.stdout
Error = {0}_{1}.stderr
Log = {0}_{1}.condor
notification = Error
notify_user = awhitbe1@FNAL.GOV
x509userproxy = $ENV(X509_USER_PROXY)
Arguments = {0} {1} {2} {3}
Queue 1""".format(options.executable,options.sample,options.name,commitHash)

outputFile = open("{0}_{1}.jdl".format(options.executable,options.name),'w')
outputFile.write(jdlFile)
outputFile.close()

##### DAGMAN will be use to manage jobs
#os.system("condor_submit {0}_{1}.jdl".format(options.executable,options.name))

