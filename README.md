Assignment 1 – Memory Management

This is your 1st assignment in the course. It covers the topics of memory management, inheritance, and polymorphism. Please read the instructions carefully before writing your program.

Application:
You are required to implement 2 types of audio players (MP3 & MP4), and a small set of operations:
•	Add: initialize a new Song (with a given ID) and add it on the player as a new link in a linked list. A link is added as the first or last link in the list, depending on the specific OPCODE.
•	Play: playing all songs is simulated by printing their IDs one by one. MP3 plays songs from first to last, while MP4 plays songs in reversed order.
•	Remove: remove a link with a given index from the player.
•	Swap: you are an index, and are required to swap the corresponding links of the Player.
•	Backup: call the backup method of the Lab object to create a deep copy of your Player.
•	Restore: call the restore method of the Lab object to let your player be a deep copy backup.

Application flow:
1.	The main function waits for the user input. if the user inputs 3 – both the player and backup should point to MP3s; if the user inputs 4 – they should be initialized as MP4s.
2.	Your main function should run a while loop that waits for user input. The user enters both an OPCODE, and the additional parameters (if necessary). An OPCODE is a number between 0-7:
a.	OPCODE = 1: add a Song to the player, as a new link to the beginning of the linked list. The ID of the Song will be given as the next parameter.
b.	OPCODE = 2: add a Song to the player, as a new link to the end of the linked list. The ID of the Song will be given in the next parameter.
c.	OPCODE = 3: play all songs.
d.	OPCODE = 4: remove a link from the player. The index of the link will be given as the next parameter.
e.	OPCODE = 5: swap two links. Their indices (i, i + 1) will be given as the next parameter.
f.	OPCODE = 6: backup.
g.	OPCODE = 7: restore.
h.	OPCODE = 0: quit the while loop, free all memory and terminate the program.

OPCODE	Command	Additional parameters
0	Quit	---
1	Add first	Song ID
2	Add last	Song ID
3	Play all	---
4	Remove	Index i – song to remove. For simplicity, i > 0 and i < size(list) - 1
5	Swap	Index i. for simplicity, i > 0 and i + 1 < size(list) - 1
6	Backup	---
7	Restore	---

Implementation:
•	You are given some code. You must use this code, and must not override it!
•	Make sure that all memory is freed before the process terminates.
•	Casting usually indicates non-generic code that cannot be easily extended. Do not use it.
•	Do not duplicate code! Store all links in the code of the base class Player, and use it for all the code that both MP3, MP4 share.
•	Implement all rule-of-5 methods, (ONLY) for classes that hold pointers.
•	You can assume valid input.

ATTENTION: You are provided below with 2 input-output examples. Your program must comply with this format! Specifically, you should not add any prints to your output.

Submission
•	The due date for submission is 7/9/2025. An extension will be given, if the class has already started working on the assignment before the coming lecture (28/8/2025).
•	Submission is in pairs.
•	Submit only .h files (which contain only declarations) and .cpp filed (which contain implementations).

Input-output 1 (MP3):
3		// in: MP3 player
2		// in: add last
1		// song ID
2		// in: add last
2		// song ID
2		// in: add last
3		// song ID
6		// in: backup
3		// in: play
1		// out
2		// out
3		// out
4		// in: remove
1		// in: index to remove
3		// in: play
1 		// out
3 		// out
7		// in: restore
3		// in: play
1		// out
2		// out
3		// out
0		// exit















Input-output 1 (MP4):
4		// in: MP4 player
1		// in: add first
1		// song ID
1		// in: add first
2		// song ID
1		// in: add first
3		// song ID
1		// in: add first
4		// song ID
3		// in: play
1		// out
2		// out
3		// out
4		// out
5		// in: swap
1		// in: indices to swap – 1,2
3		// in: play
1 		// out
3		// out
2		// out
4 		// out
0		// exit

