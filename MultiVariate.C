#define MultiVariate_cxx
// The class definition in MultiVariate.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("MultiVariate.C")
// root> T->Process("MultiVariate.C","some options")
// root> T->Process("MultiVariate.C+")
//


#include "MultiVariate.h"
#include <TH2.h>
#include <TStyle.h>
TH1 * LowerSideBand = nullptr;
TH1 * UpperSideBand = nullptr;
TH1 * SignalRegion = nullptr;
TH2D * scatterplot = nullptr; 
TCanvas *c1 = new TCanvas("c1", "c1", 900, 900);
THStack *hs = new THStack("hs", "Background Subtracted Xi_c0");

void MultiVariate::Begin(TTree * /*tree*/)
{

scatterplot = new TH2D("Entires", "IPCHI2_OWNPV vs PromptPi_ProbNNk", 100., 0, 100., 100., 0., 1.);
LowerSideBand = new TH1D("Lower Side Band", "Probability", 100, 0., 1.);
UpperSideBand = new TH1D("Upper Side Band", "Probability", 100, 0., 1.);
SignalRegion = new TH1D("Signal Region", "Probability", 100, 0., 1.);
scatterplot->GetXaxis()->SetTitle("IPCHI2_OWNPV");
scatterplot->GetYaxis()->SetTitle("PromptPi_ProbNNk");

   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void MultiVariate::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t MultiVariate::Process(Long64_t entry)
{

fReader.SetEntry(entry);
GetEntry(entry);

double Omega_MM_Corrected = (*Omega_MM) - (*Lambda_MM) + 1115.683;

bool SignalRegion =
bool LowerSideBand
bool UpperSideBand

scatterplot->Fill(*PromptPi_IPCHI2_OWNPV, *PromptPi_ProbNNk);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);

   return kTRUE;
}

void MultiVariate::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void MultiVariate::Terminate()
{
TCanvas c1;
scatterplot->Draw("colz");
c1.SaveAs("MultiAttempt.png");
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
