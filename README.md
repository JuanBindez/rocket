# Rocket

## command line automation

### Description:

Rocket is a command-line tool designed to automate command execution on Unix-like operating systems. It offers a convenient way to create and run custom scripts, making it easy to automate repetitive tasks.

### Instalation:

    git clone https://github.com/JuanBindez/rocket
    cd rocket
    make
    sudo make install

### Uninstall:

    sudo make uninstall
----------

## Usage:

#### create a file with the name rocktfile or with extension .rocketfile and inside place the commands you want to execute in sequence, for example:

    git add .
    git commit -m 'update'
    git push -u origin main
    
#### To run type:

    rocket Rocketfile

#### or:

    rocket script.rocketfile
    
this command will read the Rocketfile and execute the commands
----------

#### Rocket:

- The main focus of "Rocket" is on automating system commands and scripts, making it easier to perform daily or common tasks. It is flexible enough to handle a variety of commands beyond code compilation.
