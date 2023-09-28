# Undulating_propulsion3D
A UDF for undulation
The fin surface is built by Creo software. Firstly, use Matlab to build the fin points by referring to equation-1, then import the points data to Creo. After that, make these points into surfaces.

# Appendix A Wave data
Based on the grid partition strategy and simulation parameter settings in this paper, and using the Wavy open channel flow initialization method starting from the velocity inlet in the Fluent solver, numerical simulations were conducted for the second-order Stokes wave in the absence of the robot, as shown in the figure below(a). Considering the actual experimental conditions, this study primarily focused on simulating minor wave conditions under sea state 2, with a wave height of 0.1 meters and a wavelength of 2 meters. It can be observed in the figure that the wave height at the rear of the flow field gradually becomes gentler due to the presence of a wave-damping section at the tail, which avoids the formation of reflected waves that may affect convergence. Figure below (b) shows the wave height distribution along the course.
![image](https://github.com/sxd15963949546/undulating_propulsion3D/assets/52901076/2d8f3165-748c-4389-bf7b-f70bc8ebae2a)
(a)Waveform diagram of the second-order Stokes wave at 2 seconds; (b)Free-surface wave height distribution chart.

The figure below (a) shows the pressure distribution in the flow field under still water conditions. Due to simulating in a gravity field, the pressure exhibits stratified increments. The figure below (b) is the cloud map of pressure distribution under wave conditions. The undulation of waves causes the water level at wave crests to be higher than the still-water surface, while wave troughs are lower than the still-water surface. Therefore, the hydraulic pressure fluctuates compared to still water. Overall, both states' flow field pressure values are consistent with reality.
![image](https://github.com/sxd15963949546/undulating_propulsion3D/assets/52901076/dcf7d672-1975-42e6-aafa-4698681067e2)

# Appendix B Robot model
The robot is actuated by servos, which control the undulating motion of the fin by moving the fin rays fixed on the fin surface to specific positions. A flexible rubber sheet is chosen as the fin surface material to ensure flexibility and cut into a sector shape. Pre-tension forces are applied to both ends to make the inner edge straight. The fin surface is secured to the robot using fin rays. Following Shannon's sampling theorem, nine fin rays are determined to allow for the fitting of two complete waves in the undulating fin motion.
![附图3](https://github.com/sxd15963949546/undulating_propulsion3D/assets/52901076/a1155894-967b-4904-9e52-958a48e9475f)
![image](https://github.com/sxd15963949546/undulating_propulsion3D/assets/52901076/ec79ee7f-0f80-4213-98f4-4942a7fbf96f)

# Appendix C
Experimental diagram of single-period motion with frequency 1, wave number 1 and amplitude 15°
![image](https://github.com/sxd15963949546/undulating_propulsion3D/assets/52901076/d46edab4-3500-4d9a-9ab1-7f1a0dbb9543)

# Appendix D

![image](https://github.com/sxd15963949546/undulating_propulsion3D/blob/main/fig1.gif)
![image](https://github.com/sxd15963949546/undulating_propulsion3D/blob/main/fig2.gif)
![image](https://github.com/sxd15963949546/undulating_propulsion3D/blob/main/fig3.gif)
![image](https://github.com/sxd15963949546/undulating_propulsion3D/blob/main/fig4.gif)
![image](https://github.com/sxd15963949546/undulating_propulsion3D/blob/main/fig6.gif)
