the game works with the commands listed on the submission pdf, with the added commands of "exit" 
and "look around", the first of which exits the game properly without a winning condition, 
and the latter of which checks if there is a digit in the room the player is currently in,
to be used for unlocking the chest with the "use xyz" command, where xyz are the respected
digits found in the map in random order. if the program does not exit properly, the log file
will not be properly closed, resulting in its being not written to.