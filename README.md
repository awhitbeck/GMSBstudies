# First attempt...

<pre>
#compile:
cmsenv
g++ `root-config --cflags --glibs` -I/uscms_data/d2/awhitbe1/workArea/RA2studies/analysisFrameworkAttempt/CMSSW_7_4_2/src/AnalysisTools/src/ -I./ genericPlotter.cc -o test.exe
</pre>