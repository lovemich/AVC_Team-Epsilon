# AVC_Team-Epsilon
Team Epsilon's AVC repository.
RPi ip: 10.140.70.194

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
| ...      | ... |
Group Goal: Get robot moving in a straight line, able to control turning and have the AVC plan done.

#Week 1 Review 
 
 - Lewis came in spare time and created the base chassis.
 - Logan drawen a basic design and planned parts location.
 - Michel is resaerching how to open the gate  but has issues with lack of infomation.
 - Devon created the software for movement and also started creating line following code.
 - Brandon impemented code for sensor averaging and made sure the team got the plan done in the lab.

#Week 2
| Person | Task |
| :------------ |:---------------:| 
| Lewis   | Start outline for progress report | 
| Logan   | Finalise design ✔|
| Michael | Have started code for gate opening |
| Devon   | Have robot stop when the line is lost ✔|
| Lavanya | Write background section ✔|
| Brandon | Ensure code is done for quad 1/arrange team digital meeting ✔|
| ...      | ... |
Group Goal: Code done for quad 1

#Week 2 Review

- Lewis didn't start the outline for the progress report but made a group file that everyone could add to. Lavanya and Lewis are planning to do it next week.
- Logan finished he design and showed the group on the skype meeting.
- Michael is yet to workout how open the gate and can't find anything out about it.
- Devon has created the the code for line following and is starting the line is lost task.
- Brandon made sure that the code  is done for quad and made the group have a skpe meeting at wednesday at 6pm.

#Week 3
| Person | Task |
| :------------ |:---------------:| 
| Lewis   | Start outline for progress report/Hardware done for quadrant 1/start for 2 | 
| Logan   | Code for turning when reaching a corner/dead end |
| Michael | Start developing a way to complete the maze |
| Devon   | Keep working on code for line following and add details for running code on readme |
| Lavanya | More progress report/help with hardware |
| Brandon | Check group's progress on the progress report/add week four plan |
| ...      | ... |
Group Goal: Quadrant 1 completed/code done for quad 2


#Week 4
| Person | Task |
| :------------ |:---------------:| 
| Lewis   | Have Hardware for quad 2 ready for testing | 
| Logan   | Continue with help coding with line following code|
| Michael | Continue to work out gate issues |
| Devon   | Have line following code tested and start fixing bugs |
| Lavanya | Help with hardware/update readme documentation |
| Brandon | Update weekly planner/Help tune AVC |
| ...      | ... |
Group Goal: Finish progress report/Hardware done for Quad 2

- Week 5 Goal: Test Quad 2/Code for Quad 3/ Hardware done for Quad 3
- Week 6 Goal:Test Quad 3/ Start planning for quad 4
- Week 7 Goal: Code for Quad 4 & Hardware
- Week 8 Goal: Test everything fix bugs
- Week 9 Goal: Have robot pass all quads
