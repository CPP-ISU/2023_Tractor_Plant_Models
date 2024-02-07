# Virtual Engineering

## Setup

### Multi-Body
1. Saving Solidworks Models:
    * Save All assemblies as parts
    * Any assembly that needs to be a discrete element can be saved as its own part.
    * You want to minimize part count in the toplevel simulation assembly.
    * Make sure to use simple mate styles, (planes and coincidents instead of width mates) concentric works well
    * Generally the entire frame and op-station will be saved as one part to simplify everything
    * Wheels must be saved as parts, and all suspension components need to be one part. 
    * Make sure that the material properties get transfered when assembly gets saved.
2. Exporting Solidworks Model:
    * The assembly can now be exported to simscape, this means that you need to run the solidworks simscape plugin to export the model
    * after exporting the model, there is some things to clean up.
3. Switching out suspension and tires.
    * Suspension must be switched to use a prismatic or similar joint along the cylinder, this joint needs a spring damper linked to it if using coilovers, or a hydraulic cylinder if using hydraulic.
    * Wheels also need to be switched to the wheel simscape objects, these simplify traction.
    * Wheels also need to be connected to the drivetrain model, this allows the drivetrain to spin the wheel, allowing the tractor to drive.


## Reports

1. Saving figures: There are many graphing scripts in the 2023 plant models repo, these give examples of how to have simscape publish to the matlab workspace, and have matlab graph the data. 
2. Images: Most images can be directly screenshotted in simscape multibody.
3. Multi-run: One of the coolest ways to show the model is to tweak one parameter and run the model many times. This could be done with suspension, making a graph of RMS acceleration over suspension stiffness or damping while going through durability would allow a really cool graph.