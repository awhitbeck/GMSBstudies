import os

from optparse import OptionParser

parser = OptionParser()
parser.add_option("-s", "--sample", dest="sample", default="znunu_0_600",
                  help="sample to analyze")

parser.add_option("-n", "--name", dest="name", default="",
                  help="name for condor files")

(options, args) = parser.parse_args()

if options.name == "" : options.name = options.sample

###############################################
# I would like to have this script create a 
# new directory in my eos area every time 
# a new batch of jobs is submitted.  
# The code should check if a directory corresponding
# to the origin/master hash was created, if so, 
# report to the user and stop. If not, create the 
# directory and submit the jobs. 
###############################################

jdlFile = """universe = vanilla
Executable = worker.sh
Requirements = OpSys == "LINUX" && (Arch != "DUMMY" )
request_disk = 10000000
request_memory = 10000
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT_OR_EVICT
Transfer_Input_Files = worker.sh
PeriodicRemove = ( JobStatus == 2 ) && ( ( CurrentTime - EnteredCurrentStatus ) > 200000 )
Output = signalRegionSkim_{1}.stdout
Error = signalRegionSkim_{1}.stderr
Log = signalRegionSkim_{1}.condor
notification = Error
notify_user = awhitbe1@FNAL.GOV
x509userproxy = $ENV(X509_USER_PROXY)
Arguments = {0} {1}
Queue 1""".format(options.sample,options.name)

outputFile = open("signalRegionSkim_{0}.jdl".format(options.name),'w')
outputFile.write(jdlFile)
outputFile.close()

os.system("condor_submit signalRegionSkim_{0}.jdl".format(options.name))

