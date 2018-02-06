**Note for users of UE 4.16+:** you will need to update the build files for the project to run. You can see an example of what needs changing is [this upgrade commit](https://github.com/UnrealCourse/04_BattleTank/commit/00ac31d53915f83680628732c0fbd52cd9e527ec).

### 1 Intro, Notes & Section 4 Assets ###

+ Battle Tank is an open world tank fight
+ This will be a head to head battle 
+ Other player can be human or simple AI 
+ Heavy focus on control systems 
+ Also learning terrains, UI, terrain sculpting & more 
+ Dive right in and enjoy yourself!

### S04 Game Design Document (GDD) ###

+ The Concept, Rules and (initial) requirements
+ We’ll iterate around a loop while making this game 
+ Constantly asking “what’s least fun” 
+ Remember we’re not AAA studios 
+ Let’s find the essence of fun of this game.

### Setting Up a GitHub “Repo” ###

+ Creating an online repository for your project
+ GitHub provides public hosting for free 
+ We will use their default UnrealEngine **.gitignore**
+ We’ll then “clone” this repository to our machine 
+ How to use a **readme.md** with markdown*

### Creating & Deleting Landscapes ###

+ Creating an Unreal project in an existing “repo”
+ What’s good about Landscapes in Unreal Engine
+ How to add a Landscape in Unreal
+ How to delete a Landscape in Unreal.

### Landscape Setup & Scaling ###

+ You can change position & rotation later
+ Scale will impact terrain size, so set on creation 
+ How to choose your “Section Size” 
+ The effect of the “Number of Components” 
+ Creating a landscape of a specific scale.

### A Landscaping Process ###

+ **Sculpt: hills, valleys & flat areas**
+ **Smooth, flatten & ramp: create useful features**
+ **Erosion & noise: make it more organic**
+ Paint: use layered materials 
+ Details: add details (foliage, trees, etc)

### Upgrading Engine Version ###

+ Epic games launcher helps manage versions
+ Remember to commit your project first 
+ You can then “Convert in-place” 
+ Check your project runs OK in new version 
+ Close everything and re-commit 
+ How to tag a commit in GitHub.

### Using Landscape Layers ###

+ Create a material for your landscape
+ Set Usage > Used with Landscape 
+ LandscapeLayerBlend node & Vector Parameters 
+ Add at at least two layers & create LayerInfo 
+ Paint the landscape from the Modes tab 
+ Screenshot and share with us

### Flat Shading Low Poly Landscapes ###

+ Unreal’s tools are setup for photoreal landscapes 
+ Once you set the bar high, the rest must match 
+ An alternative is to opt for a low-poly look... 
+ ...then you can focus on gameplay, story, sound 
+ Can be a good choice for smaller teams 
+ How to make low-poly, flat-shaded landscapes.

### More Landscaping Tools ###

+ How to make flat shading optional
+ Importing and exporting landscape heightmaps 
+ Reducing the resolution of a landscape 
+ Using a texture in a landscape material.

### Tank Control System ###

+ Support keyboard, mouse & gamepad controller
+ Mapping player intentions to control inputs 
+ Mapping control inputs to actor actuators 
+ Introducing the concept of “fly by wire”.

### Actors from Multiple Meshes ###

+ Import the tank in 4 static mesh parts
+ Assemble the parts using sockets 
+ Create our Tank_BP and test.

### Configuring a Tank ###

+ Add mass to the tank
+ Fine-tune track position 
+ Replace root component in Tank_BP 
+ Enable physics and assign a mass 
+ Set the tank as the Default Pawn 
+ Setup PlayerStart and debug start collisions.

### 14 3rd Person Camera Control ###

+ Horizontal Coordinate System
+ Setup a Camera Spring Arm 
+ Why the Spring Arm alone isn’t enough 
+ How rotations don’t “commute” 
+ Binding mouse and gamepad to camera control.

### Fixing 3rd Person Camera Rotation ###

+ Use a Scene Root as azimuth gimbal
+ Use the Spring Arm for elevation control 
+ Adjust the Spring Arm length 
+ Set the camera rotation to 0 (down the arm) 
+ Decide if you want the camera to roll or not.

### User Interface (UI) in Unreal ###

+ Create a Widget Blueprint for the aim point
+ Decide the Player Controller with create the UI 
+ Create widget and add to viewport in Blueprint 
+ Override the Player Controller in the game mode.

### Main Menu Screens ###

+ Create a dedicated Scene for the Main Menu
+ Use the Level Blueprint to configure UI 
+ Add a background image to get started.

### UI Scale Box, Buttons & Mouse ###

+ Show mouse cursor in Unreal UI
+ Use a Scale Box for background image scaling
+ Add a Start button
+ Customise fonts inside our UI Widget
+ Set anchors so UI scales to different aspect ratios.

### Controller Ready Navigation ###

+ Bind Start button event to Blueprint
+ Create custom WidgetReady event
+ Make Start menu button focused on play
+ Ensure we can quit from the game
+ Aim towards Steam “Full Controller Support”.

### Trial Packaging Your Game ###

+ Creating a stand-alone game
+ Setting the first level that loads 
+ Making sure the input mode works 
+ Setting-up for “Full Controller Support”.

### Delegating to Components ###

+ How delegation can hide information
+ Creating a custom Player Controller class 
+ Re-parenting Blueprint classes onto our C++

### 22 Using virtual and override ###

+ A virtual method can be overridden by children
+ The override keyword is a sanity check 
+ Use Super:: to include parents’ functionality 
+ Use this to add BeginPlay() to PlayerController.

### 22b Overloading and Polymorphism ###

+ What is polymorphism?
+ How to overload functions.
+ Using run-time polymorphism.

### 22c Virtual Functions and Vtables ###

+ How methods are called.
+ Why we need the virtual method.
+ How Vtables implement this.
+ See how the assembly changes.

### Creating an AI Controller Class ###

+ How to create a AIController based C++ class
+ Assigning an AI Controller to a Pawn 
+ Verifying which pawns are possessed 
+ Logging possession to the console.

### Get the Player Controller with C++ ###

+ Getting the AI to find the player position
+ We won’t implement line-of-sight for simplicity 
+ **UGameplayStatics::GetPlayerController()**
+ Or **GetWorld()->GetFirstPlayerController()**

### Add Tick() to PlayerController ###

+ Revise adding engine methods into new classes
+ Pseudocode our initial aiming logic 
+ Learn about Visual Assist for Visual Studio.

### Creating an Out Parameter Method ###

+ Out parameters smell a little but are used a lot
+ Allows you to return a bool and a FVector 
+ Alternative architecture would be a struct or class 
+ We’ll do it this way to get you more comfortable with creating your own methods using out parameters.

### Finding Screen Pixel Coordinates ###

+ Use FVector2D() to store pixel coordinates
+ This is two floats, pixels can be non-integer 
+ Revising UPROPERTY(EditAnywhere) and more.

### Using DeprojectScreenToWorld ###

+ How to find the camera look direction
+ What the WorldLocation parameter does
+ WorldDirection returned is a unit vector.

### Using LineTraceSingleByChannel() ###

+ We want world position of anything visible
+ GetWorld()->LineTraceSingleByChannel()
+ Use the ECC_Visibility channel for what’s seen
+ Remember HitResult is a rich object
+ Use HitResult.Location for Location member.

### Unify Player & AI Aiming ###

+ AI and Player possessed tanks aim the same way
+ Later the tank will delegate aiming 
+ But the AI/Player controllers don’t care 
+ This provides nice abstraction 
+ We also hide implementation details 
+ … and make the game more fair.

### Create Default Sub Objects in C++ ###

+ You can add required components in C++
+ Our Tank Aiming Component is a good candidate
+ We will delegate all AimAt() requests…
+ … regardless of their source (AI or player).

### BlueprintCallable() ###

+ Why StaticMeshComponet is prefixed with U
+ Creating a setter for the barrel reference 
+ How to name parameters in setters 
+ Using BlueprintCallable() to call C++ from BP 
+ Finding the start position of or projectile.

### SuggestProjectileVelocity() ###

+ How speed and velocity relate
+ The high and low projectile arc
+ Setting a launch speed on the tank
+ Introducing **SuggestProjectileVelocity()**

### Predict Projectile Landing Point ###

+ Use **SuggestProjectileVelocity()** in Unreal
+ Work out where a projectile will land.

### 35 Using FRotators in Unreal ###

+ A FRotaor is a struct
+ It contains Roll, Pitch and Yaw as floats 
+ Convert using .Rotation() method 
+ Report aim direction as a rotator 
+ Log result to the console in Unreal.

### 35b The C++ Compilation Process ###

+ More about the Unreal Header Tool (UHT)
+ Pre-processing happens first, e.g. on macros 
+ Then compilation produces .obj files 
+ These .obj files are linked by the linker 
+ How to #include strategically.


### 36 Using Forward Declarations ###

+ If we #include in a .h file we create a “chain”
+ Any .h file that includes us will in-turn include
+ This can be hard to keep track of
+ To simply use a type, we can “forward declare”
+ Simply put class ClassName; under the includes
+ You’ll still need to #include in the .cpp to use.

### BlueprintSpawnableComponent() ###

+ In actor blueprints you have custom components
+ Static mesh components don’t appear by default 
+ Use **BlueprintSpawnableComponent** annotation 
+ Using **hidecategories = ("CategoryName")**

### Review Our Execution Flow ###

+ How to disable or enable tick on various classes
+ **GetWorld()->GetTimeSeconds()** for logging 
+ Documenting your execution flow for clarity 
+ Change parameter names for clarity.

### How to Report Bugs ###

+ If something’s weird break it down
+ Use logs or the debugger to follow each step 
+ SuggestProjectileVelocity() has a bug\* 
+ … it MUST have an optional parameter!? 
+ Moving to forward declarations.

**Useful Links**

+ \* [UE4 Answer Hub - SuggestProjectileVelocity() Behaving Badly](https://answers.unrealengine.com/questions/435995/suggestprojectilevelocity-behaving-badly.html)

### Using Clamp() to Limit Values ###

+ **FMath::Clamp\<type\>(Input, Min, Max);**
+ Very useful for restricting value ranges 
+ Clamp our Barrel’s elevation 
+ Wire it to the aiming component 
+ Test barrel elevation works.

### 43 CHALLENGE - Turret Rotation ###

This mid-section challenge will help you integrate your knowledge and really
cement what you’ve done in the past few lectures. It will also give you a
great foundation of practical understanding on which to build. Please give it
a good shot before watching my solution.

### 44 CHALLENGE - Turret Rotation Pt.2 ###

This is the 2nd part of the solution to this section’s longer challenge. We’ll
be finishing off the turret rotation, giving us complete barrel aiming control
by the end :-)

### Setting Up Projectiles ###

+ Create a public **Fire()** method on our tank
+ Bind input via Blueprint 
+ Call this new C++ method to test 
+ Create a **Projectile** class, and Blueprint it.

### Upgrading to Unreal 4.12 ###

+ Multiple versions of the engine take up GB
+ Upgrade Building Escape and Battle Tank 
+ Learn more about using source control 
+ Using Stash in source control 
+ Fixing issue with overlapping collision volumes.

### Working Round Awkward Bugs ###

+ About AutoWeld compound objects
+ Working through self-collision issues 
+ Disabling gravity on subobjects 
+ A reminder Unreal is designed for humanoids.

### Using SpawnActor<>() to Spawn ###

+ Using **TSubclassOf\<Type\>**
+ More about forward declarations 
+ How to use **GetWorld()->SpawnActor()**
+ How to spawn projectiles from a weapon.

### Projectile Movement Components ###

+ Recap use of **CreateDefaultSubobject()**
+ Use a **ProjectileMovementComponent**
+ Get our tank delegating launch to projectile.

### Making AI Tanks Fire ###

+ Inline some code for readability
+ Inlining can also be called “defactoring” 
+ Less lines of code is often better* 
+ * everything else being equal 
+ **FPlatformTime::Seconds()** is an accurate timer 
+ Make AI tanks fire on every frame.

### EditAnywhere vs EditDefaultsOnly ###

+ **EditAnywhere** allows all instances to be edited
+ For example each AI tank could be different 
+ **EditDefaultsOnly** allows “architype” editing 
+ In other words, all tanks must be the same 
+ Think which you want in future.

### Adding a Quit Button ###

+ Using primitive colliders in Unreal
+ Adding a quit button to our main menu.

### Setup Track Throttles ###

+ Base Tank Tracks on **UStaticMeshComponent**
+ Create a **BlueprintCallable** throttle method 
+ Bind input to track throttles 
+ Discuss what Input Axis Scale does.

### ApplyForceAtLocation() in Action ###

+ **GetComponentLocation()** does what it says!
+ Find root: **GetOwner()->GetRootComponent());**
+ Cast to **UPrimitiveComponent** so you can… 
+ **AddForceAtLocation();**
+ Estimate sensible defaults for driving forces.

### 55 Physics Materials & Friction ###

+ You can assign a physics material under collision
+ Friction is combined between two surfaces
+ The coefficient is the proportion of the contact force that can be exerted sideways before slip.
+ Adjust friction and driving forces to get movement.

### Fly-by-Wire Control System ###

+ Fly-by-wire means translating control intention
+ How control intention maps to track throttles 
+ Creating a **TankMovementComponent** C++ class 
+ Why inherit from **UNavMovementComponent**

### Using BlueprintReadOnly ###

+ Bind some input for forward and backward
+ Make the method **BlueprintCallable**
+ Make **TankMovementComponent** a default on tank 
+ Make a protected tank variable to store pointer 
+ Make this pointer **BlueprintReadOnly** pointer 
+ Test that you get a log of +/-1.

### A Better Component Architecture ###

+ Actor components require instance references
+ We were passing these references from the tank 
+ But we could equally keep them locally 
+ Move to composing our actor in Blueprint 
+ Create an initialise method for aiming 
+ Test it works and hail the simpler code.

### Completing Manual Tank Movement ###

+ **Add IntendTurnRight()** method
+ Bind firing input to the “A button” 
+ Test we can move manually with fly-by-wire.

### Introducing AI Pathfinding ###

+ Pathfinding is finding the shortest possible path
+ This requires some (artificial) intelligence 
+ All pathfinding must happen on a navmesh 
+ Adding Nav Mesh Bounds to the level 
+ An overview of how **MoveToActor()** and **RequestDirectMove()** work.

### Dissecting RequestDirectMove() ###

+ We have access to Unreal’s source code
+ Let’s look into the **UNavMovementComponent.h**
+ We’re looking for **RequestDirectMove()**
+ We’ll override it without calling **Super**
+ We can then get the golden **MoveVelocity** vector 
+ AI tanks can now use our fly-by-wire controls!

### DotProduct() Vector Operator ###

+ Focusing on controlling forward speed of AI
+ If target in front, move forward full speed 
+ If target to side, don’t move forward 
+ Vary smoothly in-between 
+ This sounds like a cosine function to me! 
+ Using **FVector::DotProduct()**

### CrossProduct() Vector Operator ###

+ Focusing on controlling turning of AI
+ If target in front or behind* don’t rotate 
+ If target to side rotate at full speed 
+ This is the behaviour of a sin function 
+ Using **FVector::CrossProduct()**

### Finalising Your Class Code ###

+ Private, protected or public? Use the safest
+ UPROPERY / UFUNCTION needed? Use “” 
+ **#include** and forward declarations required?

### How to Use Blueprint Variables ###

+ Remember “what’s the least fun thing about this?”
+ One thing is not knowing if you can fire 
+ How to change crosshair colour in blueprint… 
+ … according to the aiming component state 
+ States: Locked, Aiming, Reloading 
+ Referencing actor component from player UI.

### Using Enum(erations) in UE4 ###

+ We met **enum class** around lecture 35
+ In Unreal we must annotate with **UENUM()**
+ We must specify the storage type (**uint8**) 
+ See Unreal’s coding standards in Resources 
+ Remember we use enums to encode meaning.

### Refactoring our Aiming Component ###

+ Move away from **CreateDefaultSubObject()**
+ Make aiming a **BlueprintSpawanableComponent**
+ Get our code re-compiling as soon as possible
+ Experience hard crash and add pointer protection
+ Possibly get exasperated that we can’t find the suspected null-pointer causing the crash.

### Attaching a Debugger to Unreal ###

+ Hard crashes can be difficult to diagnose
+ Attach your IDE’s debugger to the Unreal editor 
+ Use it to discover the source (often null pointer) 
+ We can also probe using Print in blueprint.

### Constructor & Begin Play Timing ###

+ Adding log entries to C++ and BP helps you to uncover the timing over events in the engine
+ We’re doing this to discover exactly when Construct and Begin Play gets called in both C++ and Blueprint 
+ Note dropped actors are constructed in editor.

### Decoupling Your Architecture ###

+ We don’t have a Aiming Component reference
+ It is hard to find a sensible time to set it
+ Also we don’t need the reference on the tank
+ We can Get Components by Class in Blueprint
+ Mock-up our C++ code in Blueprint.

### BlueprintImplementableEvent ###

+ We want to expose a C++ function to Blueprint
+ We also want to pass a parameter (aiming ref.) 
+ Multicast delegates only work like this for actors 
+ We’re using a component so we use… 
+ **UFUNCTION(BlueprintImplementableEvent)**
+ You don’t need to define the function!

### Using the ensure Assertion ###



### Dependency Mapping ###

+ Code architecture can be hard to see
+ Dependency mapping shakes-out the structure 
+ Go through your .cpp files and look at includes 
+ Map these as dependencies on a diagram 
+ If it looks like spaghetti, you need to refactor!

### Talking Head - Real World Skills ###

+ Congratulations on getting this far
+ We’re not teaching sterile solutions here 
+ We’re showing you how to recognise real issues 
+ … and how to tackle them sensibly 
+ It’s not the easy path, but it is the valuable one.

### Starting From Green ###

+ You should probably only refactor working code
+ Red means your code’s not working 
+ Green means it is, even if the code is messy 
+ We commit at green, then start refactoring.

### Aiming Without the Tank ###

+ There is no need to cast the Pawn to a Tank
+ Doing so creates a dependency we don’t want 
+ Remember a Tank is a Pawn 
+ We simplify our architecture here.

### Finishing our Refactoring ###

+ Removing our final dependencies
+ If you override **BeginPlay()** in an actor you should call **Super::BeginPlay()**
+ If you don’t override it at all, there’s no need to, your Blueprint Begin Play will still run.

### Adding TickComponent() Back ###

+ Actor Components use **TickComponent** not **Tick**
+ You can find the signature in docs online 
+ Or by copying from the engine code 
+ Remember to use **override** at to check 
+ Remember to set the boolean in the constructor 
+ **GetWorld()->GetTimeSeconds()** alternative.

### 79 Are Two Floats Equal? ###

+ FVectors are just structs containing float
+ You must “define equal” when comparing floats
+ The **FVector::Equals()** method allows this
+ Specify a tolerance, see docs in resources.

### 80 Programmatic Sideways Friction ###

+ We can apply a sideways correction force
+ Remember Force = Mass * Acceleration
+ … and Acceleration = Speed / Time
+ So we calculate the force using the slippage speed,the frame time, and the tank mass
+ A way to calculate is **FVector::DotProduct()**

### 81 OnComponentHit Event in 4.12 ###

+ We could use OnComponentHit in Blueprint
+ But we’re grown-ups so we’re going to use C++
+ Signature of **OnHit(...)** has changed in 4.12
+ Remember you need to make it a **UFUNCTION**
+ Details on next slide.

### Avoiding Boolean Flags ###

+ Boolean flags usually make answers old
+ Try and think of a way of avoiding them 
+ Revise the use of **FMath::Clamp()**

### Improving Tank Aiming ###

+ Use a literal glass ceiling to help with testing!
+ Sometimes the barrel takes the long route 
+ A simple **if()** statement can help here 
+ Find and fix another bug in the code 
+ You can use **%i** formatter to log booleans.

### Tweaking Tank AI ###

+ Expose the Acceptance Radius to blueprint
+ Tweak that value as **EditAnywhere**
+ Change back to **EditDefaultsOnly** once found 
+ Prevent AI tanks firing until aiming is locked.

### Making an Ammo Display ###

+ Add a 4th enum state for out of ammo
+ Work around bug of blueprint select nodes not updating when we add new enum values in C++ 
+ Add a display for rounds remaining 
+ Bind the UI to a **GetRounds()** method.

### Making an AutoMortar ###

+ The tank components were built for the tank
+ It turns-out we can re-use movement and aiming 
+ This is the benefit of re-usable components 
+ We’ll create a self-aiming mortar tower.

### Using the Reference Viewer ###

+ Currently we .gitignore the Starter Content
+ Therefore we can’t track changes 
+ We want a consistent starting point for particles 
+ So we’re going to delete Starter Content 
+ Lots depends on it so we use a special tool 
+ That special tool is the reference viewer.

### Preparing for Particles ###

+ We will compose our projectile in C++
+ Use **SetRootComponent**() 
+ Use **AttachTo(RootComponent)**
+ You can set default properties in C++ 
+ Use **UPROPERTY(VisibleAnywhere)**

### Introducing Particle Systems ###

+ Setup a Starter Content project
+ Use it to migrate assets to Battle Tank 
+ Explore particle systems 
+ Use world space for smoke trails 
+ Create and share your smoke trail.

### Particle Bounding Boxes ###

+ Our smoke disappeared when viewed from side
+ This is due to the fixed particle bounding boxes 
+ We can fix it by making the boxes dynamic 
+ BUT we need to remove GPU rendered particles 
+ … and test the performance hit is acceptable.

### Using FAttachmentTransformRules ###

+ Use Message Log to see warnings
+ **AttachTo()** has become **AttachToComponent()**
+ Now must provide **FAttachmentTransformRules**
+ We’ll use **KeepRelativeTransform** for now 
+ Write code to de-active launch blast and 
+ Activate impact blast on impact.

### Radial Forces & Caching ###

+ If you don’t **AttachToComponent()** then…
+ It will look like you’re attached but… 
+ The transform may be broken and… 
+ You’ll get really weird effects and… 
+ Unreal may cache the issue...
+ So, always **AttachToComponent()** :-)

### Using GetTimerManager() ###

+ Currently we don’t destroy our projectiles
+ This will cause slow-down and memory leakage 
+ You won’t pass console testing with a leak 
+ Tidy up after ourselves 
+ Discuss projectile schemes 
+ Destroy our projectiles with a timer.

### Using TakeDamage() on Actors ###

+ Unreal has an actor damage system
+ We’ll apply radial damage from the projectile 
+ Then the **AActor::TakeDamage()** method will be called on the tank (and all other actors in radius) 
+ We’ll then finish our damage system off 
+ Solve the **int** or **float** damage question.

### BlueprintPure & Health Bars ###

+ Add a UI Widget component to our tank
+ Make a very simple health progress bar 
+ Wire the bar to the tank.

### The Observer Pattern ###



### Finishing Off - Part 1 ###

+ We’re nearing the end of the section
+ You have several challenges over to try
+ These include various fixes and improvements...
+ Use **StartSpectatingOnly()** in Player Controller
+ **DetachFromControllerPendingDestroy()** in AI
+ Fixing a bug with our starting health

### Finishing Off - Part 2 ###

+ You can use the noise function on landscapes
+ Gameobjects are automatically destroyed when they travel a long way from the play area 
+ Reviewing Unreal’s coding standards.

### Section 4 Wrap-Up ###

In this section we covered...
+ Basic terrain landscaping
+ Using and modifying the AI pathfinding system 
+ A deep-dive into control systems 
+ User Interface for the first time 
+ A whole tonne of C++ and architecture.

### Bonus - Switching Cameras ###

+ Our player controller line traces to aim
+ This can hit the UI in some circumstances
+ Change our line trace channel to ECC::Camera
+ Add a 1st person camera
+ Use the Toggle Visibility Blueprint node
+ Bind input and enjoy simple camera swapping.
