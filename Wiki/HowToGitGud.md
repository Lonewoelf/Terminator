<h1> How To Git Gud </h1>

Git can be used by either using the commandline interface, or the GUI.<br>
This guide will explain both ways.

<h3> Commandline </h3>

First go to https://gitforwindows.org/ and download git bash (git commandline). <br>
Then follow the install wizard, once everything has been set-up, the fun begins.

To start using the git repo, you need to clone it to your computer. You can do this by right clicking inside the desired directory on you PC <br>
and then clicking on `Git Bash here`, a command line will open. <br>
Type `git clone https://github.com/Lonewoelf/Terminator.git` inside this command line to get a local copy of the repo.

Open a Bash commandline inside the newly made copy of the repo.
To see the files inside one of the branches you have to type `git checkout <branch name> `.
To create a new branch type `git checkout -b <new branch name> ` <br> followed by a `git push -u origin <new branch name>`

If you want to update your local copy of the repo, type `git pull Development`.<br>
But if you want to push you changes to the online version of the repo, do the following<br>
`git add --all`<br>
`git commit -m <descriptive message>`
`git push`

Once your new feature is finished create a pull request from your branch to developement, and add a reviewer.
In case of any merge conflicts please contact Madita.

<h3> Git Desktop </h3>

First go to https://desktop.github.com/ and follow the install procedure.<br>
On the `Let's get starte!` page please single click on `LoneWoelf/Terminator` and <br> then the button `Clone Lonewoelf/Terminator`<br>

The GUI is pretty self explanatory, on the branch tab one can create branches.
By clicking `Fetch origin` one can update the local version of the branch.
