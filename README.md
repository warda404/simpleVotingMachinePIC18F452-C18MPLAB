# simpleVotingMachinePIC18F452-C18MPLAB

In normal mode -> Voting is disabled (Red LED is ON, Green LED is OFF)
Press Control Button to enable (GREEN on, RED off)

ENABLE mode -> Voting by pressing CAN1, CAN2 or CAN3 
As soon as CAN1 or CAN2 or CAN3 is pressed, machine goes back into DISABLE mode

ENABLE mode -> VIEW STATUS button -> displays the number of votes for each candidate

ENABLE mode -> FINAL RESULT button -> displays the winner of the voting & resets all votes to 0
