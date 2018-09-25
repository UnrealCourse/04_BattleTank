# Unreal Engine Developer Course - Section 4 - Battle Tank

This is the [Unreal Engine Developer]( http://gdev.tv/urcgithub) course – it started as a runaway success on Kickstarter and has gone on to become one of the bestselling Unreal courses on the internet! Continually updated in response to student suggestions, you will benefit from the fact we have already taught over 360,336 students game development, many shipping commercial games as a result.

You're welcome to download, fork or do whatever else legal with all the files! The real value is in our huge, high-quality online tutorials that accompany this repo. You can check out the course here: [Unreal Engine Developer]( http://gdev.tv/urcgithub)

## In This Section

### 1 Intro, Notes & Section 4 Assets ###

+ Battle Tank is an open world tank fight
+ This will be a head to head battle
+ Other player can be human or simple AI
+ Heavy focus on control systems
+ Also learning terrains, UI, terrain sculpting & more
+ Dive right in and enjoy yourself!

### 1b Battle Tank Overview ###

* An overview of the finished Battle Tank project.

### 2 S04 Game Design Document (GDD) ###

+ The Concept, Rules and (initial) requirements
+ We’ll iterate around a loop while making this game
+ Constantly asking “what’s least fun”
+ Remember we’re not AAA studios
+ Let’s find the essence of fun of this game.

### 3 Setting Up a GitHub “Repo” ###

+ Creating an online repository for your project
+ GitHub provides public hosting for free
+ We will use their default UnrealEngine **.gitignore**
+ We’ll then “clone” this repository to our machine
+ How to use a **readme.md** with markdown*

### 4 Creating & Deleting Landscapes ###

+ Creating an Unreal project in an existing “repo”
+ What’s good about Landscapes in Unreal Engine
+ How to add a Landscape in Unreal
+ How to delete a Landscape in Unreal.

### 5 Landscape Setup & Scaling ###

+ You can change position & rotation later
+ Scale will impact terrain size, so set on creation
+ How to choose your “Section Size”
+ The effect of the “Number of Components”
+ Creating a landscape of a specific scale.

### 6 A Landscaping Process ###

+ **Sculpt: hills, valleys & flat areas**
+ **Smooth, flatten & ramp: create useful features**
+ **Erosion & noise: make it more organic**
+ Paint: use layered materials
+ Details: add details (foliage, trees, etc)

### 7 Upgrading Engine Version ###

+ Epic games launcher helps manage versions
+ Remember to commit your project first
+ You can then “Convert in-place”
+ Check your project runs OK in new version
+ Close everything and re-commit
+ How to tag a commit in GitHub.

### 8 Using Landscape Layers ###

+ Create a material for your landscape
+ Set Usage > Used with Landscape
+ LandscapeLayerBlend node & Vector Parameters
+ Add at at least two layers & create LayerInfo
+ Paint the landscape from the Modes tab
+ Screenshot and share with us

### 9 Flat Shading Low Poly Landscapes ###

+ Unreal’s tools are setup for photoreal landscapes
+ Once you set the bar high, the rest must match
+ An alternative is to opt for a low-poly look...
+ ...then you can focus on gameplay, story, sound
+ Can be a good choice for smaller teams
+ How to make low-poly, flat-shaded landscapes.

### 10 More Landscaping Tools ###

+ How to make flat shading optional
+ Importing and exporting landscape heightmaps
+ Reducing the resolution of a landscape
+ Using a texture in a landscape material.

### 11 Tank Control System ###

+ Support keyboard, mouse & gamepad controller
+ Mapping player intentions to control inputs
+ Mapping control inputs to actor actuators
+ Introducing the concept of “fly by wire”.

### 12 Actors from Multiple Meshes ###

+ Import the tank in 4 static mesh parts
+ Assemble the parts using sockets
+ Create our Tank_BP and test.

### 13 Configuring a Tank ###

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

### 15 Fixing 3rd Person Camera Rotation ###

+ Use a Scene Root as azimuth gimbal
+ Use the Spring Arm for elevation control
+ Adjust the Spring Arm length
+ Set the camera rotation to 0 (down the arm)
+ Decide if you want the camera to roll or not.

### 16 User Interface (UI) in Unreal ###

+ Create a Widget Blueprint for the aim point
+ Decide the Player Controller with create the UI
+ Create widget and add to viewport in Blueprint
+ Override the Player Controller in the game mode.

### 17 Main Menu Screens ###

+ Create a dedicated Scene for the Main Menu
+ Use the Level Blueprint to configure UI
+ Add a background image to get started.

### 18 UI Scale Box, Buttons & Mouse ###

+ Show mouse cursor in Unreal UI
+ Use a Scale Box for background image scaling
+ Add a Start button
+ Customise fonts inside our UI Widget
+ Set anchors so UI scales to different aspect ratios.

### 19 Controller Ready Navigation ###

+ Bind Start button event to Blueprint
+ Create custom WidgetReady event
+ Make Start menu button focused on play
+ Ensure we can quit from the game
+ Aim towards Steam “Full Controller Support”.

### 20 Trial Packaging Your Game ###

+ Creating a stand-alone game
+ Setting the first level that loads
+ Making sure the input mode works
+ Setting-up for “Full Controller Support”.

### 21 Delegating to Components ###

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

### 23 Creating an AI Controller Class ###

+ How to create a AIController based C++ class
+ Assigning an AI Controller to a Pawn
+ Verifying which pawns are possessed
+ Logging possession to the console.

### 24 Get the Player Controller with C++ ###

+ Getting the AI to find the player position
+ We won’t implement line-of-sight for simplicity
+ **UGameplayStatics::GetPlayerController()**
+ Or **GetWorld()->GetFirstPlayerController()**

### 25 Add Tick() to PlayerController ###

+ Revise adding engine methods into new classes
+ Pseudocode our initial aiming logic
+ Learn about Visual Assist for Visual Studio.

### 26 Creating an Out Parameter Method ###

+ Out parameters smell a little but are used a lot
+ Allows you to return a bool and a FVector
+ Alternative architecture would be a struct or class
+ We’ll do it this way to get you more comfortable with creating your own methods using out parameters.

### 27 Finding Screen Pixel Coordinates ###

+ Use FVector2D() to store pixel coordinates
+ This is two floats, pixels can be non-integer
+ Revising UPROPERTY(EditAnywhere) and more.

### 28 Using DeprojectScreenToWorld ###

+ How to find the camera look direction
+ What the WorldLocation parameter does
+ WorldDirection returned is a unit vector.

### 29 Using LineTraceSingleByChannel() ###

+ We want world position of anything visible
+ GetWorld()->LineTraceSingleByChannel()
+ Use the ECC_Visibility channel for what’s seen
+ Remember HitResult is a rich object
+ Use HitResult.Location for Location member.

### 30 Unify Player & AI Aiming ###

+ AI and Player possessed tanks aim the same way
+ Later the tank will delegate aiming
+ But the AI/Player controllers don’t care
+ This provides nice abstraction
+ We also hide implementation details
+ … and make the game more fair.

### 31 Create Default Sub Objects in C++ ###

+ You can add required components in C++
+ Our Tank Aiming Component is a good candidate
+ We will delegate all AimAt() requests…
+ … regardless of their source (AI or player).

### 32 BlueprintCallable() ###

+ Why StaticMeshComponet is prefixed with U
+ Creating a setter for the barrel reference
+ How to name parameters in setters
+ Using BlueprintCallable() to call C++ from BP
+ Finding the start position of or projectile.

### 33 SuggestProjectileVelocity() ###

+ How speed and velocity relate
+ The high and low projectile arc
+ Setting a launch speed on the tank
+ Introducing **SuggestProjectileVelocity()**

### 34 Predict Projectile Landing Point ###

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

### 37 BlueprintSpawnableComponent() ###

+ In actor blueprints you have custom components
+ Static mesh components don’t appear by default
+ Use **BlueprintSpawnableComponent** annotation
+ Using **hidecategories = ("CategoryName")**

### 40 Review Our Execution Flow ###

+ How to disable or enable tick on various classes
+ **GetWorld()->GetTimeSeconds()** for logging
+ Documenting your execution flow for clarity
+ Change parameter names for clarity.

### 41 How to Report Bugs ###

+ If something’s weird break it down
+ Use logs or the debugger to follow each step
+ SuggestProjectileVelocity() has a bug\*
+ … it MUST have an optional parameter!?
+ Moving to forward declarations.

**Useful Links**

+ \* [UE4 Answer Hub - SuggestProjectileVelocity() Behaving Badly](https://answers.unrealengine.com/questions/435995/suggestprojectilevelocity-behaving-badly.html)

### 42 Using Clamp() to Limit Values ###

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

### 45 Setting Up Projectiles ###

+ Create a public **Fire()** method on our tank
+ Bind input via Blueprint
+ Call this new C++ method to test
+ Create a **Projectile** class, and Blueprint it.

### 46 Upgrading to Unreal 4.12 ###

+ Multiple versions of the engine take up GB
+ Upgrade Building Escape and Battle Tank
+ Learn more about using source control
+ Using Stash in source control
+ Fixing issue with overlapping collision volumes.

### 47 Working Round Awkward Bugs ###

+ About AutoWeld compound objects
+ Working through self-collision issues
+ Disabling gravity on subobjects
+ A reminder Unreal is designed for humanoids.

### 48 Using SpawnActor<>() to Spawn ###

+ Using **TSubclassOf\<Type\>**
+ More about forward declarations
+ How to use **GetWorld()->SpawnActor()**
+ How to spawn projectiles from a weapon.

### 49 Projectile Movement Components ###

+ Recap use of **CreateDefaultSubobject()**
+ Use a **ProjectileMovementComponent**
+ Get our tank delegating launch to projectile.

### 50 Making AI Tanks Fire ###

+ Inline some code for readability
+ Inlining can also be called “defactoring”
+ Less lines of code is often better*
+ * everything else being equal
+ **FPlatformTime::Seconds()** is an accurate timer
+ Make AI tanks fire on every frame.

### 51 EditAnywhere vs EditDefaultsOnly ###

+ **EditAnywhere** allows all instances to be edited
+ For example each AI tank could be different
+ **EditDefaultsOnly** allows “architype” editing
+ In other words, all tanks must be the same
+ Think which you want in future.

### 52 Adding a Quit Button ###

+ Using primitive colliders in Unreal
+ Adding a quit button to our main menu.

### 53 Setup Track Throttles ###

+ Base Tank Tracks on **UStaticMeshComponent**
+ Create a **BlueprintCallable** throttle method
+ Bind input to track throttles
+ Discuss what Input Axis Scale does.

### 54 ApplyForceAtLocation() in Action ###

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

### 56 Fly-by-Wire Control System ###

+ Fly-by-wire means translating control intention
+ How control intention maps to track throttles
+ Creating a **TankMovementComponent** C++ class
+ Why inherit from **UNavMovementComponent**

### 57 Using BlueprintReadOnly ###

+ Bind some input for forward and backward
+ Make the method **BlueprintCallable**
+ Make **TankMovementComponent** a default on tank
+ Make a protected tank variable to store pointer
+ Make this pointer **BlueprintReadOnly** pointer
+ Test that you get a log of +/-1.

### 58 A Better Component Architecture ###

+ Actor components require instance references
+ We were passing these references from the tank
+ But we could equally keep them locally
+ Move to composing our actor in Blueprint
+ Create an initialise method for aiming
+ Test it works and hail the simpler code.

### 59 Completing Manual Tank Movement ###

+ **Add IntendTurnRight()** method
+ Bind firing input to the “A button”
+ Test we can move manually with fly-by-wire.

### 60 Introducing AI Pathfinding ###

+ Pathfinding is finding the shortest possible path
+ This requires some (artificial) intelligence
+ All pathfinding must happen on a navmesh
+ Adding Nav Mesh Bounds to the level
+ An overview of how **MoveToActor()** and **RequestDirectMove()** work.

### 61 Dissecting RequestDirectMove() ###

+ We have access to Unreal’s source code
+ Let’s look into the **UNavMovementComponent.h**
+ We’re looking for **RequestDirectMove()**
+ We’ll override it without calling **Super**
+ We can then get the golden **MoveVelocity** vector
+ AI tanks can now use our fly-by-wire controls!

### 62 DotProduct() Vector Operator ###

+ Focusing on controlling forward speed of AI
+ If target in front, move forward full speed
+ If target to side, don’t move forward
+ Vary smoothly in-between
+ This sounds like a cosine function to me!
+ Using **FVector::DotProduct()**

### 63 CrossProduct() Vector Operator ###

+ Focusing on controlling turning of AI
+ If target in front or behind* don’t rotate
+ If target to side rotate at full speed
+ This is the behaviour of a sin function
+ Using **FVector::CrossProduct()**

### 64 Finalising Your Class Code ###

+ Private, protected or public? Use the safest
+ UPROPERY / UFUNCTION needed? Use “”
+ **#include** and forward declarations required?

### 65 How to Use Blueprint Variables ###

+ Remember “what’s the least fun thing about this?”
+ One thing is not knowing if you can fire
+ How to change crosshair colour in blueprint…
+ … according to the aiming component state
+ States: Locked, Aiming, Reloading
+ Referencing actor component from player UI.

### 66 Using Enum(erations) in UE4 ###

+ We met **enum class** around lecture 35
+ In Unreal we must annotate with **UENUM()**
+ We must specify the storage type (**uint8**)
+ See Unreal’s coding standards in Resources
+ Remember we use enums to encode meaning.

### 67 Refactoring our Aiming Component ###

+ Move away from **CreateDefaultSubObject()**
+ Make aiming a **BlueprintSpawanableComponent**
+ Get our code re-compiling as soon as possible
+ Experience hard crash and add pointer protection
+ Possibly get exasperated that we can’t find the suspected null-pointer causing the crash.

### 68 Attaching a Debugger to Unreal ###

+ Hard crashes can be difficult to diagnose
+ Attach your IDE’s debugger to the Unreal editor
+ Use it to discover the source (often null pointer)
+ We can also probe using Print in blueprint.

### 69 Constructor & Begin Play Timing ###

+ Adding log entries to C++ and BP helps you to uncover the timing over events in the engine
+ We’re doing this to discover exactly when Construct and Begin Play gets called in both C++ and Blueprint
+ Note dropped actors are constructed in editor.

### 70 Decoupling Your Architecture ###

+ We don’t have a Aiming Component reference
+ It is hard to find a sensible time to set it
+ Also we don’t need the reference on the tank
+ We can Get Components by Class in Blueprint
+ Mock-up our C++ code in Blueprint.

### 71 BlueprintImplementableEvent ###

+ We want to expose a C++ function to Blueprint
+ We also want to pass a parameter (aiming ref.)
+ Multicast delegates only work like this for actors
+ We’re using a component so we use…
+ **UFUNCTION(BlueprintImplementableEvent)**
+ You don’t need to define the function!

### 72 Using the ensure Assertion ###



### 73 Dependency Mapping ###

+ Code architecture can be hard to see
+ Dependency mapping shakes-out the structure
+ Go through your .cpp files and look at includes
+ Map these as dependencies on a diagram
+ If it looks like spaghetti, you need to refactor!

### 74 Talking Head - Real World Skills ###

+ Congratulations on getting this far
+ We’re not teaching sterile solutions here
+ We’re showing you how to recognise real issues
+ … and how to tackle them sensibly
+ It’s not the easy path, but it is the valuable one.

### 75 Starting From Green ###

+ You should probably only refactor working code
+ Red means your code’s not working
+ Green means it is, even if the code is messy
+ We commit at green, then start refactoring.

### 76 Aiming Without the Tank ###

+ There is no need to cast the Pawn to a Tank
+ Doing so creates a dependency we don’t want
+ Remember a Tank is a Pawn
+ We simplify our architecture here.

### 77 Finishing our Refactoring ###

+ Removing our final dependencies
+ If you override **BeginPlay()** in an actor you should call **Super::BeginPlay()**
+ If you don’t override it at all, there’s no need to, your Blueprint Begin Play will still run.

### 78 Adding TickComponent() Back ###

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

### 82 Avoiding Boolean Flags ###

+ Boolean flags usually make answers old
+ Try and think of a way of avoiding them
+ Revise the use of **FMath::Clamp()**

### 83 Improving Tank Aiming ###

+ Use a literal glass ceiling to help with testing!
+ Sometimes the barrel takes the long route
+ A simple **if()** statement can help here
+ Find and fix another bug in the code
+ You can use **%i** formatter to log booleans.

### 84 Tweaking Tank AI ###

+ Expose the Acceptance Radius to blueprint
+ Tweak that value as **EditAnywhere**
+ Change back to **EditDefaultsOnly** once found
+ Prevent AI tanks firing until aiming is locked.

### 85 Making an Ammo Display ###

+ Add a 4th enum state for out of ammo
+ Work around bug of blueprint select nodes not updating when we add new enum values in C++
+ Add a display for rounds remaining
+ Bind the UI to a **GetRounds()** method.

### 86 Making an AutoMortar ###

+ The tank components were built for the tank
+ It turns-out we can re-use movement and aiming
+ This is the benefit of re-usable components
+ We’ll create a self-aiming mortar tower.

### 87 Using the Reference Viewer ###

+ Currently we .gitignore the Starter Content
+ Therefore we can’t track changes
+ We want a consistent starting point for particles
+ So we’re going to delete Starter Content
+ Lots depends on it so we use a special tool
+ That special tool is the reference viewer.

### 88 Preparing for Particles ###

+ We will compose our projectile in C++
+ Use **SetRootComponent**()
+ Use **AttachTo(RootComponent)**
+ You can set default properties in C++
+ Use **UPROPERTY(VisibleAnywhere)**

### 89 Introducing Particle Systems ###

+ Setup a Starter Content project
+ Use it to migrate assets to Battle Tank
+ Explore particle systems
+ Use world space for smoke trails
+ Create and share your smoke trail.

### 90 Particle Bounding Boxes ###

+ Our smoke disappeared when viewed from side
+ This is due to the fixed particle bounding boxes
+ We can fix it by making the boxes dynamic
+ BUT we need to remove GPU rendered particles
+ … and test the performance hit is acceptable.

### 91 Using FAttachmentTransformRules ###

+ Use Message Log to see warnings
+ **AttachTo()** has become **AttachToComponent()**
+ Now must provide **FAttachmentTransformRules**
+ We’ll use **KeepRelativeTransform** for now
+ Write code to de-active launch blast and
+ Activate impact blast on impact.

### 92 Radial Forces & Caching ###

+ If you don’t **AttachToComponent()** then…
+ It will look like you’re attached but…
+ The transform may be broken and…
+ You’ll get really weird effects and…
+ Unreal may cache the issue...
+ So, always **AttachToComponent()** :-)

### 93 Using GetTimerManager() ###

+ Currently we don’t destroy our projectiles
+ This will cause slow-down and memory leakage
+ You won’t pass console testing with a leak
+ Tidy up after ourselves
+ Discuss projectile schemes
+ Destroy our projectiles with a timer.

### 94 Using TakeDamage() on Actors ###

+ Unreal has an actor damage system
+ We’ll apply radial damage from the projectile
+ Then the **AActor::TakeDamage()** method will be called on the tank (and all other actors in radius)
+ We’ll then finish our damage system off
+ Solve the **int** or **float** damage question.

### 95 BlueprintPure & Health Bars ###

+ Add a UI Widget component to our tank
+ Make a very simple health progress bar
+ Wire the bar to the tank.

### 96 The Observer Pattern ###



### 97 Finishing Off - Part 1 ###

+ We’re nearing the end of the section
+ You have several challenges over to try
+ These include various fixes and improvements...
+ Use **StartSpectatingOnly()** in Player Controller
+ **DetachFromControllerPendingDestroy()** in AI
+ Fixing a bug with our starting health

### 98 Finishing Off - Part 2 ###

+ You can use the noise function on landscapes
+ Gameobjects are automatically destroyed when they travel a long way from the play area
+ Reviewing Unreal’s coding standards.

### 99 Section 4 Wrap-Up ###

In this section we covered...
+ Basic terrain landscaping
+ Using and modifying the AI pathfinding system
+ A deep-dive into control systems
+ User Interface for the first time
+ A whole tonne of C++ and architecture.

### 100 Bonus - Switching Cameras ###

+ Our player controller line traces to aim
+ This can hit the UI in some circumstances
+ Change our line trace channel to ECC::Camera
+ Add a 1st person camera
+ Use the Toggle Visibility Blueprint node
+ Bind input and enjoy simple camera swapping.

### 100b Fixing The Tank Suspension ###

+ Why the suspension is broken.
+ How we will fix it with a suspension.
+ Overview of how suspension works.

### 101 Upgrade to 4.19 And Bug Fixes ###

**In this video (objectives)…**

1. Update the project.
2. Fix any build errors.
3. Fix any bad log messages.

**After watching (learning outcomes)…**

Can upgrade your own projects to 4.19.


### 102 Real-world Vehicle Physics ###

**In this video (objectives)…**

1. Discuss why the tank pops.
2. Identify why real world vehicles don't.
3. Create a physics model for our tank.

**After watching (learning outcomes)…**

Explain how to model a vehicle in a physics engine.

### 103 Creating Physics Constraints ###

**In this video (objectives)…**

1. Introduce the physics constraint component.
2. Combine two components with a constraint.
3. Tweak the limits of a constraint.

**After watching (learning outcomes)…**

Create a physics constraint between two components and set limits.

### 104 Making Springs ###

**In this video (objectives)…**

1. Explain position drive.
2. Introduce the theory of springs.
3. Explain velocity drive.
4. Making a suspension.

**After watching (learning outcomes)…**

Create a spring using the `UPhysicsConstraintComponent` and linear drives.

### 105 Converting The Spring To C++ ###

**In this video (objectives)…**

1. Create a base class.
2. Create all components.
3. Configure the blueprint.

**After watching (learning outcomes)…**

Create Blueprint children of C++ classes derived from `AActor`.

### 106 Attachment, Actors and Components ###

**In this video (objectives)…**

1. Attachment with actors and components.
2. Using `GetAttachParentActor`.
3. Creating a spawning component.

**After watching (learning outcomes)…**

Understand component versus actor childing.

### 107 SpawnActorDeferred and BeginPlay ###

**In this video (objectives)…**

1. Spawning and `BeginPlay`.
2. Using `SpawnActorDeferred`.

**After watching (learning outcomes)…**

Able to spawn actors using `SpawnActorDeferred` and know when it's needed.

### 108 Attaching Constraints In C++ ###

**In this video (objectives)…**

1. Remove the mass.
2. Introducing `SetConstrainedComponents`
3. Set constraint to the tank root.
4. Add more wheels.
5. Tweak the spring parameters.


**After watching (learning outcomes)…**

Setup constraints between actors in C++.

### 109 Chaining Physics Constraints ###

**In this video (objectives)…**

1. Chaining constraints together.
2. Setup the new Axle and its contraint.
3. Why we need a collider to simulate physics.
4. Using `USphereComponent`s.
5. Disabling collisions on the Axle.
6. Constraining the wheel rotation.

**After watching (learning outcomes)…**

How to chain constraints together.

### 110 Applying Wheel Driving Force ###

**In this video (objectives)…**

1. Exposing `AddDrivingForce()`.
2. The requirements for `GetWheels()`.
3. Update `DriveTrack()` to apply for all wheels.
4. Remove `OnHit()` and `ApplySidewaysForce()`.
5. How to iterate over child components.

**After watching (learning outcomes)…**

Iterate over child components.

### 111 Solution: Implement GetWheels() ###

Continued...

6. Add getter to the `SpawnPoint`.
7. Implementing `GetWheels()`.

### 112 Tick Groups And Physics ###

**In this video (objectives)…**

1. Detecting no collision.
2. Understanding Tick Groups and their order.
3. When does `OnHit` get called?
4. Apply force on collision or reset.

**After watching (learning outcomes)…**

An understanding of the Tick Group Order and how it interacts with physics notifications.

### 113 Tweaking Linear & Angular Damping ###

**In this video (objectives)…**

1. Making a testing level.
2. Changing linear damping.
3. Tweak linear damping.
4. Tweak angular damping.
5. Add more wheels.

**After watching (learning outcomes)…**

Understand how damping affects the tank.

### 114 BONUS: Fixing Collider Issues ###

How to workaround the "ConvexElem Invalid" errors.
