#define Xi_c0_cxx
// The class definition in Xi_c0.h has been generated automatically
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
// root> T->Process("Xi_c0.C")
// root> T->Process("Xi_c0.C","some options")
// root> T->Process("Xi_c0.C+")
//

TH1 * strippingLevelXiLDDMassHist = nullptr;
TH1 * strippingLevelXiDDDMassHist = nullptr;
TH1 * strippingLevelXiLLLMassHist = nullptr;
TH1 * strippingLevelXiDLLMassHist = nullptr;
TH1 * backgroundsubtractedXi = nullptr;

const int TRACK_LONG = 3;
const int TRACK_DOWN = 5;

#include "fit1MeV_Gaussian.C"//this file is currently missing in the repo
#include "Xi_c0.h"
#include <TH2.h>
#include <TStyle.h>
#include <functional>

void Xi_c0::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
	strippingLevelXiLDDMassHist = new TH1D("XiLDD, Omega- K+", "LDD: Stripping Level Cuts", 100, 2320, 3100);
	strippingLevelXiDDDMassHist = new TH1D("XiDDD, Omega- K+", "DDD: Stripping Level Cuts", 100, 2320, 3100);
	strippingLevelXiLLLMassHist = new TH1D("XiLLL, Omega- K+", "LLL: Stripping Level Cuts", 100, 2320, 3100);
	strippingLevelXiDLLMassHist = new TH1D("XiDLL Omega- K+", "DLL: StrippingLevel Cuts", 100, 2320, 3100);
	backgroundsubtractedXi = new TH1D("Background Noise", "Xi LL Background Subtracted", 100, 2320, 3100);

	//One way to think about the task at hand is in terms of selection/histogram pairs.
  //You can initialize the functors representing the selections and the TH1s here.

  //this is a functor. it is relatively new in C++ (came with C++11). What you do here is the following:
  // you declare a function object that takes a double and integer and returns a boolean, i.e. pass or fail the selection.
  // (sidenote: the double and int are passed by reference (& meaning that no copy is made) and declared const, since we know they don't change value in the functor)
  // This functor will only do something useful when we evaluate it later in the event loop (during Xi_c0::Process)
  // More on the syntax: std::function<bool(const double&, const int&)> is the type of our functor. std::function<T> is "templated" meaning that you can specify T to be anything you want.
  // Our functor object is called GoodLambdaLL and we will evaluate it later with GoodLambdaLL(foo,bar);
  // The rest = [] () {}; is a so called C++ Lambda which defines an inline function
  std::function<bool(const double&, const int&)> GoodLambdaLL = [&TRACK_LONG] (const double& current_LambdaPr_ProbNNp,
                                                                const int& current_LambdaPr_TRACK_Type) -> bool {
    return current_LambdaPr_ProbNNp > 0.1 && current_LambdaPr_TRACK_Type == TRACK_LONG;
  };
  // We can do the same with an Omega selection. To be able to use the LambdaLL functor, we "capture" it by reference. This is written as [&GoodLambdaLL]
  std::function<bool(const double&, const int&, const double&, const int&)> GoodOmegaLLL
      = [&GoodLambdaLL,&TRACK_LONG] (const double& current_LambdaPr_ProbNNp, const int& current_LambdaPr_TRACK_Type,
        const double& current_Lambda_M, const int& current_OmegaK_TRACK_Type) -> bool {
    return GoodLambdaLL(current_LambdaPr_ProbNNp, current_LambdaPr_TRACK_Type) &&
        1112 < current_Lambda_M && current_Lambda_M < 1120 && current_OmegaK_TRACK_Type == TRACK_LONG;
  };

  //now we make functor-histogram pairs. we declare a vector for this
  std::vector<std::pair<std::function,TH1D>> histos;
  histos.emplace_back(GoodLambdaLL,("LambdaLL",";M_{inv} (p#pi^{-}) (MeV); Candidates/0.25 MeV", 120, 1100, 1130));
  histos.emplace_back(GoodOmegaLLL,("OmegaLLL",";M_{inv} (#Lambda K^{-}) (MeV); Candidates/0.5 MeV", 100, 1650, 1700));

}

void Xi_c0::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t Xi_c0::Process(Long64_t entry)
{
fReader.SetEntry(entry);
GetEntry(entry);

//in a perfect world everything would essentially collapse to this:
for(auto& h : histos)
  if(h.first(...))
    h.second.Fill();

//however, you might have already noticed that not all the std::function s we would like to set up have the same template parameters inside their <> brackets.
// we could always give all the information of the current entry to the functor, but this is suboptimal.
// the root developers thus moved away from PROOF and TTreeReader and adapted the very sophisticated solution of "just in time" (JIT) compilation for these sort of problems.
// This is nicely coded up in "RDataFrame" and is the new standard since about a year or 2.
// This is something new to learn, but I guess it will pay off soon.
// If you like, you can use code that I have developed which hides all the C++ magic.
// Have a look at https://github.com/uc-lhcb/ntuple-gizmo/ , especially https://github.com/uc-lhcb/ntuple-gizmo/blob/master/doc/chain2histRDF.md
// and https://github.com/uc-lhcb/ntuple-gizmo/blob/master/config/template_chain2histRDF.info
// (note that some links are broken since they are treated different in gitlab and github)

double Xic0_mass = *Xi_c0_MM;
	
	bool GoodXiLDD = (

		(Xic0_mass > 2300. && Xic0_mass < 3100.)
		//&&(*Xi_c0_IPCHI2_OWNPV > 0)
		//&&(*Xi_c0_IPCHI2_OWNPV < 5)

		//&&(*Omega_MM > 1665 && *Omega_MM < 1680)
		//&&(*Omega_IPCHI2_OWNPV > 0)
		//&&(*Omega_IPCHI2_OWNPV < 20)
		
		//&&(*OmegaK_TRACK_Type == TRACK_LONG)
		//&&(*OmegaK_ProbNNk > 0.5)
		
		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		&&(*Lambda_IPCHI2_OWNPV > 0)
		&&(*Lambda_IPCHI2_OWNPV < 400)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_ProbNNpi > 0.05)	
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)

		);
	
	bool GoodXiDDD = (
		
		(Xic0_mass > 2300. && Xic0_mass < 3100)
		&&(*Xi_c0_IPCHI2_OWNPV > 0)
		&&(*Xi_c0_IPCHI2_OWNPV < 5)

		&&(*Omega_MM > 1665 && *Omega_MM < 1680)
		&&(*Omega_IPCHI2_OWNPV > 0)
		&&(*Omega_IPCHI2_OWNPV < 20)

		&&(*OmegaK_TRACK_Type == TRACK_DOWN)
		&&(*OmegaK_ProbNNk > 0.5)

		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		&&(*Lambda_IPCHI2_OWNPV > 0)
		&&(*Lambda_IPCHI2_OWNPV < 500)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_DOWN)

		&&(*LambdaPi_ProbNNpi > 0.1)
		&&(*LambdaPi_TRACK_Type == TRACK_DOWN)
	
		);

	bool GoodXiLLL = (
		
		(Xic0_mass > 2300. && Xic0_mass < 3100)
		&&(*Xi_c0_IPCHI2_OWNPV > 0)
		&&(*Xi_c0_IPCHI2_OWNPV < 5)

		&&(*Omega_MM > 1665 && *Omega_MM < 1680)
		&&(*Omega_IPCHI2_OWNPV > 0)
		&&(*Omega_IPCHI2_OWNPV < 20)

		&&(*OmegaK_TRACK_Type == TRACK_LONG)
		&&(*OmegaK_ProbNNk > 0.5)

		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		&&(*Lambda_IPCHI2_OWNPV > 0)
		&&(*Lambda_IPCHI2_OWNPV < 500)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_LONG)

		&&(*LambdaPi_ProbNNpi > 0.1)
		&&(*LambdaPi_TRACK_Type == TRACK_LONG)
		
		);

	bool GoodXiDLL = (
		
		(Xic0_mass > 2300. && Xic0_mass < 3100)
		&&(*Xi_c0_IPCHI2_OWNPV > 0)
		&&(*Xi_c0_IPCHI2_OWNPV < 5)

		&&(*Omega_MM > 1665 && *Omega_MM < 1680)
		&&(*Omega_IPCHI2_OWNPV > 0)
		&&(*Omega_IPCHI2_OWNPV < 20)

		&&(*OmegaK_TRACK_Type == TRACK_DOWN)
		&&(*OmegaK_ProbNNk > 0.5)

		&&(*Lambda_MM > 1112 && *Lambda_MM < 1120)
		&&(*Lambda_IPCHI2_OWNPV > 0)
		&&(*Lambda_IPCHI2_OWNPV < 500)

		&&(*LambdaPr_ProbNNp > 0.1)
		&&(*LambdaPr_TRACK_Type == TRACK_LONG)

		&&(*LambdaPi_ProbNNpi > 0.1)
		&&(*LambdaPi_TRACK_Type == TRACK_LONG)
		
		);




	bool SubtractedXiLL = (
		(Xic0_mass > 2300. && Xic0_mass < 3100.)
		&&(*Xi_c0_FDCHI2_OWNPV > 33)
		&&(*Xi_c0_FDCHI2_OWNPV < 50)
		&&(*Omega_MM > 1650 && *Omega_MM < 1665)
		&&(*Omega_MM > 1680 && *Omega_MM < 1698)
		&&(*OmegaK_ProbNNe > 0.05)
		&&(*OmegaK_ProbNNe < 1)
		&&(*OmegaK_ProbNNpi > 0.1)
		&&(*OmegaK_ProbNNpi < 1)
		&&(*OmegaK_ProbNNghost > 0.1)
		&&(*OmegaK_ProbNNghost < 1)
		&&(*OmegaK_ProbNNk > 0)
		&&(*OmegaK_ProbNNk < 0.6)
		);
		

	if (GoodXiLDD)
		strippingLevelXiLDDMassHist->Fill(*Xi_c0_MM);
	
	if (GoodXiLLL)
		strippingLevelXiLLLMassHist->Fill(*Xi_c0_MM);
	
	if (GoodXiDLL)
		strippingLevelXiDLLMassHist->Fill(*Xi_c0_MM);

	if (GoodXiDDD)
		strippingLevelXiDDDMassHist->Fill(*Xi_c0_MM);

	if (SubtractedXiLL)
		backgroundsubtractedXi->Fill(*Xi_c0_MM);


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

   return kTRUE;
}

void Xi_c0::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Xi_c0::Terminate()
{
TCanvas c1;
strippingLevelXiLDDMassHist->Draw();
//backgroundSubtractedXi->Draw();
c1.SaveAs("Xi_c0_fit.png");
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
