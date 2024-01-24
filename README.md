# Makeline



## command line automation

### Description:

Makeline is a command-line tool designed to automate command execution on Unix-like operating systems. It offers a convenient way to create and run custom scripts, making it easy to automate repetitive tasks.

### Instalation:

    git clone https://github.com/JuanBindez/Makeline
    cd Makeline
    make
    sudo make install

### Uninstall:

    sudo make uninstall
----------

## Usage:

#### create a file with the name Makeline or with extension .Makeline and inside place the commands you want to execute in sequence, for example:

    git add .
    git commit -m 'update'
    git push -u origin main
    
#### To run type:

    makeline Makeline

#### or:

    makeline script.Makeline
    
this command will read the Makeline file and execute the commands
----------

#### Makeline:

- The main focus of "Makeline" is on automating system commands and scripts, making it easier to perform daily or common tasks. It is flexible enough to handle a variety of commands beyond code compilation.
