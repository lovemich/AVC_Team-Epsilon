# AVC_Team-Epsilon
Team Epsilon's AVC repository.
RPi ip: 10.140.93.39

## Running the code
### Clone the repository if necessary.
```bash
git clone http://github.com/lovemich/AVC_Team-Epsilon
```
### Pull latest changes from the repository.
This step is not required if you have just cloned the repo.
```bash
git pull
```
### (Optional step) Now you can build the code.
To build, use the command `make`.
If you are not using the RPi the `make` command will fail as the libE101.so library is compiled for the RPi only. In this situation please instead use `make nolink`. Note that using this command will not verify that the correct variables or methods are being used, only that the syntax is correct. This command will not generate any runnable files; for that you'll need the RPi.
### Run the code
You can run the code with **either** of these commands.
```bash
make run
./main
```
Using the `make run` command is preferred as it will automatically build any modified files. If you use the second option, you *will* have to use `make` to build the binary.

If that doesn't work, you may need to run with root priviledges. You may use any of the following to run as root
```bash
make sudo_run
sudo make run
sudo ./main
```
Remember that the last option there will require first using `make` to build the binary.

## Conflicting Times
- Phys114 - 21st April, term test 1 - Lewis ✔
- Phys122 - 22nd April, term test 1 - Lavanya, Logan, Michael, Brandon, Devon ✔
- Mid-tri break - 23rd April - 2nd May - Lewis, Lavanya, Logan, Michael, Devon, Brandon ✔
- Comp102 - 9th May, term test 2 - Lewis, Lavanya, Logan, Michael
- Engr121 - 16th - 20th May, term test 2 - Lewis, Lavanya, Logan, Michael, Devon, Brandon
- Engr101 - 30th May, term test 2 - Lewis, Lavanya, Logan, Michael, Devon, Brandon

- Comp102 assignments every week - Lewis, Lavanya, Logan, Michael
- Comp112 assignments every two weeks - Brandon, Devon
- Phys114 assignments every week - Lewis
- Phys122 assignments every week - Lavanya, Logan, Michael, Devon, Brandon

- Engr121 assignments every week - Lewis, Lavanya, Logan, Michael, Devon, Brandon
- Engr121 two week labs with a week gap between them - Lewis, Lavanya, Logan, Michael, Devon, Brandon

Lavanya works:
- Wednesday 3:30-6:30pm
- Some Saturday and Sunday’s lunch rush

Brandon works:
- Wednesday 5:00-6:00pm

#Week 1
| Person | Task |
| :------------ |:---------------:|
| Lewis   | Create base chassis ✔|
| Logan   | Draw basic design, organise components (wheels, support parts etc) ✔||
| Michael | Research networking on how to open the gate/create github project ✔|
| Devon   | Write software for movement (forwards and turning) ✔|
| Lavanya | Setup readme in github ✔|
| Brandon | Implement sensor averaging/ensure AVC plan is done ✔|
| ...  	| ... |
Group Goal: Get robot moving in a straight line, able to control turning and have the AVC plan done.

#Week 1 Review
 
 - Lewis came in spare time and created the base chassis.
 - Logan drawn a basic design and planned parts location.
 - Michel is researching how to open the gate  but has issues with lack of information.
 - Devon created the software for movement and also started creating line following code.
 - Lavanya setup the readme and created the weekly plan layout.
 - Brandon implemented code for sensor averaging and made sure the team got the plan done in the lab.

#Week 2
| Person | Task |
| :------------ |:---------------:|
| Lewis   | Help Plan AVC hardware in team meeting ✔|
| Logan   | Finalise design ✔|
| Michael | Have started code for gate opening ✔|
| Devon   | Have work on more line following code ✔|
| Lavanya | Suggest coding solutions, talk about the challenges we would have with software  ✔|
| Brandon | Ensure code is done for quad 1/arrange team digital meeting ✔|
| ...  	| ... |
Group Goal: Code done for quad 1 ✔

#Week 2 Review

- Lewis help suggest his ideas for the team in the meeting and helped logan plan for the hardware design ✔
- Logan finished the design and showed the group on the skype meeting. ✔
- Michael is yet to workout how open the gate and can't find anything out about it. ✔
- Devon has created the the code for line following and is starting the line is lost task. ✔
- Lavanya suggested ideas about the code layout and talked about issues we would have with the maze in the team meeting ✔
- Brandon made sure that the code is done for quad and made the group have a skype meeting at wednesday at 6pm. ✔

#Week 3
| Person | Task |
| :------------ |:---------------:|
| Lewis   | Hardware done for quadrant 1/start for 2 ✔|
| Logan   | Start Planning for maze code ✔|
| Michael | Complete the code for the gate opening  ✔|
| Devon   | Keep working on code for line following and add details for running code on readme ✔|
| Lavanya | help with hardware/look through the code ✔ |
| Brandon | Check group's progress on the progress report/add week four plan/Help tune DVI ✔|
| ...  	| ... |
Group Goal: Quadrant 1 completed/code done for quad 2 ✔

#Week 3 Review

- Lewis has got the hardware for quad 1,2,3 ready and also helped tune the AVC ✔
- Logan has created ideas on how to deal with the maze and planned methods of turning and backing up ✔
- Michael has gotten the code for the gate work 100% now✔
- Devon has kept working on the line following code and all he has to do now is tune dvi values ✔
- Lavanya helped putting the AVC back together after camera died as we had to pull it apart to replace the camera ✔
- Brandon has helped tune the DVI with devon on wednesday for 3 hours, Planned for next week  and put the AVC back together after camera died✔

#Week 4
| Person | Task |
| :------------ |:---------------:|
| Lewis   | Create a Battery Holder for the AVC ✔|
| Logan   | Continue with help coding with maze code ✔|
| Michael | Come with a method of mounting the IR sensors  |
| Devon   | Have line following code tested and start fixing bugs ✔|
| Lavanya | Help with hardware/update readme documentation ✔|
| Brandon | Update weekly planner/Help tune AVC line following code ✔|
| ...  	| ... |
Group Goal: Finish progress report/Hardware done for Quad 2 and line following code done 

#Week 4 Review

- Lewis has created a mount for the battery for the AVC, printed it and added it to the avc ✔
- Logan is working on the maze code and coming up with ideas how deal with different challenges presented by the maze ✔
- Michal helped a little with the hardware but didn't do his task that he was set 
- Devon has sections 1 and 2 working 100% and has started work on section 3 ✔
- Lavanya helped tune the line folliwng code and helped update the readme documentation ✔
- Brandon helped devon debug and suggeted different ideas on tunning values and how to deal with the bugs✔


#Week 5
| Person | Task |
| :------------ |:---------------:|
| Lewis   | Create Code to tell if it’s a dead end & come up with ideas for the IR sensor mounts ✔|
| Logan   | work on the maze code and create the start code for section 4 ✔|
| Michael | Create/Print 3D models for AVC sensors|
| Devon   | Have quad 1,2,3 at 100% working without interaction (Mainly done ✔) |
| Lavanya | Code for maze dead backing up ✔ |
| Brandon | Start work on Maze code/ Plan for next week and write up week progress ✔|
| ...  	| ... |
Group Goal: Test for Quad 3/ Sensors start to be added 

#Week 5 Review

- Lewis completed the code to tell whether the bot comes up to a dead end in the maze.
- Logan worked on the maze code.
- Michael didn't turn up to the lab.
- Devon had the quadrant 1, 2 and partially quad 3 done without human interaction.
- Lavanya completed the coding she was meant to do and wrote up the weekly reflection.
- Brandon was busy with the maze code and helped write it up.

#Week 6 
| Person | Task |
| :------------ |:---------------:|
| Lewis   | Have hardware ready for section 4 asap |
| Logan   | Work on the maze code|
| Michael | Come up with ideas to improve the look of the avc and create them|
| Devon   | Have quad 4 at 100% working without interaction |
| Lavanya | Look into the idea of having a speaker and playing music on the avc and help improve the aesthetic |
| Brandon | Work on section 4 code/help team mates with code understanding/help test|
| ...  	| ... |
Group Goal: Have everything ready to be tested for section 4!

- Week 7 Goal: Show the AVC go through sections 1,2,3,4

