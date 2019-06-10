# Xic0ToOmegaK
The purpose of Xi_c0ToOmegaK is to measure the mass of Xi_c0 by making cuts on the daughter particle properties measured in the cascade produced by a proton-proton collision.  

To analyze  myOmegamKpTuple_0.root from 2015 I created the macros Xi_c0.C & Xi_c0.h using gVim which can be ran in root using 
DecayTree->Process("Xi_c0.C").
The file takes data from Xi_c0_MM  which was constructed through each directly measured daughter particle. It begins with filtering through ProbNN, Measured Mass, and IP_CHI2_OWNPV tuples. As the data points pass the criteria I set, the passed data points are then added to a new histogram to acheive a clearer signal in order to read the mass of Xi_c0.


The ultimate goal is to get clean a signal for the masses of each particle in order to produce the mass for Xi_c0. The underlying reason for this is to compare the 2015 data which has a clean signal to the 2016 data which has more background than expected.
