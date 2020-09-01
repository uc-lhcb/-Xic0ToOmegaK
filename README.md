# Xic0ToOmegaK
The purpose of Xi_c0ToOmegaK is to measure the mass of Xi_c0 by making cuts on the daughter particle properties measured in the cascade produced by a proton-proton collision.  

To analyze data collected from 2017, I created the macros Xi_c0_2017.C & Xi_c0_2017.h using gVim which can be ran in root using 
DecayTree->Process("Xi_c0_2017.C").
The file takes data from Xi_c0_MM  which was constructed through each directly measured daughter particle. It begins with filtering through ProbNN, Measured Mass, and IP_CHI2_OWNPV tuples. As the data points pass the criteria I set, the passed data points are then added to a new histogram to acheive a clearer signal in order to read the mass of Xi_c0.
This gives a reasonable fit to the graph when these variables are applied. Not the best fit though. So in order to find the best cut we adjust every value for the variables and find the fit with the lowest uncertainty which was done in Multivariate_V2.C
There are better methods which can be performed to find a better fit and they were test in OneD_MV_EB_V2.C

The ultimate goal is to get clean a signal for the masses of each particle in order to produce the mass for Xi_c0. The underlying reason for this is to compare the 2015 data which has a clean signal to the 2016 data which has more background than expected. The 2017 data will be used to find a more precise measurement of Xi_c0
