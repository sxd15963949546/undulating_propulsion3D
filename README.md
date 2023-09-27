# undulating_propulsion3D
A UDF for undulation
The fin surface is built by Creo software. Firstly, use Matlab to build the fin points by referring to equation-1, then import the points data to Creo. After that, make these points into surfaces.

Appendix A
Based on the grid partition strategy and simulation parameter settings in this paper, and using the Wavy open channel flow initialization method starting from the velocity inlet in the Fluent solver, numerical simulations were conducted for the second-order Stokes wave in the absence of the robot, as shown in the figure below(a). Considering the actual experimental conditions, this study primarily focused on simulating minor wave conditions under sea state 2, with a wave height of 0.1 meters and a wavelength of 2 meters. It can be observed in the figure that the wave height at the rear of the flow field gradually becomes gentler due to the presence of a wave-damping section at the tail, which avoids the formation of reflected waves that may affect convergence. Figure below (b) shows the wave height distribution along the course.
![image](https://github.com/sxd15963949546/undulating_propulsion3D/assets/52901076/2d8f3165-748c-4389-bf7b-f70bc8ebae2a)
(a)Waveform diagram of the second-order Stokes wave at 2 seconds; (b)Free-surface wave height distribution chart.

The figure below (a) shows the pressure distribution in the flow field under still water conditions. Due to simulating in a gravity field, the pressure exhibits stratified increments. The figure below (b) is the cloud map of pressure distribution under wave conditions. The undulation of waves causes the water level at wave crests to be higher than the still-water surface, while wave troughs are lower than the still-water surface. Therefore, the hydraulic pressure fluctuates compared to still water. Overall, both states' flow field pressure values are consistent with reality.
![image](https://github.com/sxd15963949546/undulating_propulsion3D/assets/52901076/dcf7d672-1975-42e6-aafa-4698681067e2)


