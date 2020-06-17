#define Testing_cxx

#include "Testing.h"
#include <TH2.h>
#include <TStyle.h>
#include <TGraph.h>

using namespace std;
const int n = 2;

TGraph *gr = new TGraph;

void Testing::Begin(TTree * /*tree*/)
{

  std::array<double,n> x{-4131., 4131}, y{0.065, -0.065};

  gr = new TGraph(n, x, y);

   TString option = GetOption();
}

void Testing::SlaveBegin(TTree * /*tree*/)
{

   TString option = GetOption();

}

Bool_t Testing::Process(Long64_t entry)
{

   fReader.SetLocalEntry(entry);

   return kTRUE;
}

void Testing::SlaveTerminate()
{
}

void Testing::Terminate()
{

}
