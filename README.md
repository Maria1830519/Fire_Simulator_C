# Fire_Simulator_C
The simulation consists of a forest of trees with a burning tree whose fire can be spread 
through the neighbour trees during the simulation. The map of the forest was created with a 2D 
array of “Cell” objects with a size of 21x21, with a 1-Cell boundary of empty Cells (that 
works as a real fireback). The forest is drawn with ASCII symbols where:
• ‘0’ means “Empty”, and it is assigned to the map’s boundary and to Burnt 
trees.
• ‘*’ means “Tree”, and it is assigned to the Trees on the map.
• ‘#’ means “Burning”, and it is assigned to the Burning Trees on the map.

In terms of Functionality, the simulation starts with the map being draw with the 
symbols mentioned above. A cell on fire is set somewhere in the map (the basic 
simulation required this to be on the centre of the map, but as an enhancement, this was 
programmed to appear somewhere random). During every time-period, a tree with a 
burning neighbour has a probability of being set on fire. Weather affects this 
probability: there are three possible Weather Types, Dry, Normal and Raining; each of 
them determinates a maximum probability of a Cell being set on fire. Dry set a 
maximum probability of 80%, Normal of 50% and Raining, 35%. The weather can 
change on the different periods of time, it is not the same during the whole simulation. 
When a tree is on fire, on the next time-period will appear as an empty Cell (0 symbol). 
This burnt trees can “respawn” during the simulation (there is a 15% chance of this 
happening), being able to burn again if the circumstances say so. 
The simulation keeps working and the map is updated on every time-period. The 
simulation ends when there is not a single tree on fire. See APPENDIX for the 
Simulation Instructions
