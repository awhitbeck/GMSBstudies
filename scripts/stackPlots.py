from ROOT import *
gROOT.SetBatch(True)

gROOT.ProcessLine(".L ~/tdrstyle.C")
gROOT.ProcessLine("setTDRStyle()")

def plot( var , _file0 ) : 
    ZJets = _file0.Get("{0}_ZJetsToNuNu".format(var))
    if not ZJets : 
        print "Couldn't get {0}_ZJetsToNuNu".format(var)
        return
    ZJets.SetFillColor(kCyan)
    ZJets.SetLineColor(1)
    ZJets.SetLineWidth(2)
    TT = _file0.Get("{0}_TTJets".format(var))
    if not TT : 
        print "Couldn't get {0}_TTJets".format(var)
        return    
    TT.SetFillColor(kBlue)
    TT.SetLineColor(1)
    TT.SetLineWidth(2)
    QCD = _file0.Get("{0}_QCD".format(var))
    if not QCD : 
        print "Couldn't get {0}_QCD".format(var)
        return
    QCD.SetFillColor(kOrange)
    QCD.SetLineColor(1)
    QCD.SetLineWidth(2)
    WJets = _file0.Get("{0}_WJetsToLNu".format(var))
    if not WJets : 
        print "Couldn't get {0}_WJetsToLNu".format(var)
        return
    WJets.SetFillColor(kGreen+1)
    WJets.SetLineColor(1)
    WJets.SetLineWidth(2)
    GJets = _file0.Get("{0}_GJets".format(var))
    if not GJets : 
        print "Couldn't get {0}_GJets".format(var)
        return
    GJets.SetFillColor(kMagenta+1)
    GJets.SetLineColor(1)
    GJets.SetLineWidth(2)
    
    s = THStack("{0}Stack".format(var),"{0}Stack".format(var))
    WJets.SetMinimum(.1)
    s.Add(WJets)
    s.Add(ZJets)
    s.Add(TT)
    s.Add(GJets)
    s.Add(QCD)
    s.SetMinimum(.1)

    can = TCanvas("can","can",500,500)

    s.Draw("HIST")
    s.GetXaxis().SetNdivisions(505)
    s.GetYaxis().SetNdivisions(505)
    
    leg = TLegend(.65,.65,.9,.9)
    leg.SetBorderSize(0)
    leg.SetFillColor(0)
    leg.AddEntry(WJets,"W+jets","f")
    leg.AddEntry(ZJets,"Z+jets","f")
    leg.AddEntry(TT,"top","f")
    leg.AddEntry(GJets,"#gamma+jets","f")
    leg.AddEntry(QCD,"QCD","f")
    leg.Draw()

    can.SaveAs("{0}_stack.png".format(var))
    can.SetLogy()
    can.SaveAs("{0}_stackLogY.png".format(var))
    
from optparse import OptionParser
parser = OptionParser()
parser.add_option("-v", "--var", dest="var",default="MHT_SR",
                  help="variable to plot")
(options, args) = parser.parse_args()

_file0 = TFile("fullAnalysis_all.root","READ")

var = options.var
plot(var,_file0)
