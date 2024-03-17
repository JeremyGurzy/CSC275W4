#include <iostream>
//Allows us to utilize threads
#include <thread>
//Allows us to utilize lock 
#include <mutex>
//Allows us to use sleep, pause and clear function
#include <Windows.h>

//Allows us to not have to type std on every line
using namespace std;

//global variables available throughout the program, const means you cannot change it
//Number of threads, I have 7 because I want 6 to display
const int numThreads = 7;

//Number of targets for a thread
const int numTargets = 7;

//mutex is the lock, locks data until released
mutex MLock;

//local thread id
int localTID = 0;

//STEP 1 CREATE A FUNCTION
//Function that will have all of the threads run, this will be attached to every thread
void openHatchThread(int tid)
{ //Starting scope operator, this starts a code block
	
	//This is the locking, everything after this is locked and nobody can get at it until I unlock it
	MLock.lock();

	//name our local thread variable tid
	localTID = tid;

	//If created to take out 0 when displaying number of threads
	if (localTID != 0) 
	{ //Starting scope operator, this starts a code block

		//cout will display the local thread ID
		cout << "Hatch " << localTID << " has opened" << endl;
	}// Ending scope operator, this end a block of code
	//Time delay function
	Sleep(500);

	//recommend writing an unlock statment after you write the lock, unlocks the data
	MLock.unlock();
}// Ending scope operator, this end a block of code
//Created function for thread STEP 1
void missileLaunchThread(int tid) 
{ //Starting scope operator, this starts a code block

	//This is the locking, everything after this is locked and nobody can get at it until I unlock it
	MLock.lock();

	//name our local thread variable tid
	localTID = tid;

	//If created to take out 0 when displaying number of threads
	if (localTID != 0)
	{ //Starting scope operator, this starts a code block
		//cout will display with the local thread
		cout << "Missile launching from hatch " << localTID << endl;
	} // Ending scope operator, this end a block of code
	//Time delay function
	Sleep(200);
	//recommend writing an unlock statment after you write the lock, unlocks the data
	MLock.unlock();


} // Ending scope operator, this end a block of code
//Created function for thread STEP 1
void missileHitThread(int tid)
{ //Starting scope operator, this starts a code block

	//This is the locking, everything after this is locked and nobody can get at it until I unlock it
	MLock.lock();

	//name our local thread variable tid
	localTID = tid;

	//If created to take out 0 when displaying number of threads
	if (localTID != 0)
	{ //Starting scope operator, this starts a code block
		//cout will display with the local thread
		cout << "Missile " << localTID <<  " HIT the target" << endl;
	} // Ending scope operator, this end a block of code

	//Time delay function
	Sleep(200);

	//recommend writing an unlock statment after you write the lock, unlocks the data
	MLock.unlock();
} // Ending scope operator, this end a block of code

//Created function for thread STEP 1
void closeHatchThread(int tid)
{ //Starting scope operator, this starts a code block

	//This is the locking, everything after this is locked and nobody can get at it until I unlock it
	MLock.lock();

	//name our local thread variable tid
	localTID = tid;

	//If created to take out 0 when displaying number of threads
	if (localTID != 0)
	{ //Starting scope operator, this starts a code block
		//cout will display with the local thread
		cout << "Hatch " << localTID << " has closed" << endl;
	} // Ending scope operator, this end a block of code

	//This is for time delays, time is in milliseconds so 500 is 5 milliseconds
	Sleep(500);

	//recommend writing an unlock statment after you write the lock, unlocks the data
	MLock.unlock();
} // Ending scope operator, this end a block of code


//Function for just dialogue in the beginning
void dialogue()
{ //Starting scope operator, this starts a code block
	//All couts display dialogue
	cout << "\n\nWelcome to USS Voltron C++05! Today we are going out to sea to launch a couple missiles.";
	cout << "\nYou get to come along and hit the buttons! Now let's get into it!";
	cout << "\n\nYou will be launching six missiles, we will be firing at giant red targets out in the ocean!";
	cout << "\nWhenever you are ready follow the command below!\n\n";
	
} // Ending scope operator, this end a block of code


//Our main function
int main()
{ //Starting scope operator, this starts a code block
	//cout for title
	cout << "\t\t\t*** Missile Launch Simulation ***" << endl;
	//call dialogue function
	dialogue();
	//pause function so user can read
	system("pause");

	cout << "\nInitiating hatch opening sequence...\n\n";

	//STEP 2 CREATE THE THREAD
	//create a thread, the number of threads is the number we assigned it to
	thread openingThreads[numThreads];

	//attach them to the call from thread
	for (int i = 0; i < numThreads; i++)
	{ //Starting scope operator, this starts a code block

		//STEP 3 ASSOCIATE THE THREAD WITH THE FUNCTION AND ANY INPUT IT NEEDS
		openingThreads[i] = thread(openHatchThread, i);

	} // Ending scope operator, this end a block of code

	//For statement for joining the threads
	for (int i = 0; i < numThreads; i++)
	{ //Starting scope operator, this starts a code block

		//joinable simply returns a boolean
		if (openingThreads[i].joinable())
		{ //Starting scope operator, this starts a code block
			//STEP 4 WE JOIN IT
			//join says take this thread and run that function
			openingThreads[i].join();

		} // Ending scope operator, this end a block of code
		//else will dislay if thread NOT joined
		else
		{ //Starting scope operator, this starts a code block
			cout << "\n\n*** ERROR OPENING HATCH STAND CLEAR ***" << i << endl;

		} // Ending scope operator, this end a block of code

	} // Ending scope operator, this end a block of code
	
	//All couts from here will display what is going on and dialogue
	cout << "\nAll hatches OPENED." << endl;
	cout << "\nNow that the hatches are open we are ready to start launching!";
	cout << "\nWhenever you are ready, follow the command below.\n\n";

	//Pauses program until user hits any button
	system("pause");

	cout << "\nInitiating launch sequence...\n\n";

	//Create the thread STEP 2
	thread launchThreads[numThreads];

	//attach them to the call from thread
	for (int i = 0; i < numThreads; i++)
	{ //Starting scope operator, this starts a code block
		//Associate the thread STEP 3 
		launchThreads[i] = thread(missileLaunchThread, i);

	} // Ending scope operator, this end a block of code
	 
	//For statement for joining the threads
	for (int i = 0; i < numThreads; i++)
	{ //Starting scope operator, this starts a code block

		//joinable simply returns a boolean
		if (launchThreads[i].joinable())
		{ //Starting scope operator, this starts a code block
			//STEP 4 WE JOIN IT
			//join says take this thread and run that function
			launchThreads[i].join();

		} // Ending scope operator, this end a block of code
		//else will dislay if thread NOT joined
		else
		{ //Starting scope operator, this starts a code block
			cout << "\n\n*** ERROR LAUNCHING MISSILE STAND BACK ***" << i << endl;
 
		} // Ending scope operator, this end a block of code

	} // Ending scope operator, this end a block of code

	cout << "\n\nAcquiring targets....targets acquired.\n\n";

	//Time delay function
	Sleep(600);

	//Create the thread STEP 2
	thread hitThreads[numTargets];

	//attach them to the call from thread
	for (int i = 0; i < numTargets; i++)
	{ //Starting scope operator, this starts a code block

		//Associate the thread STEP 3 
		hitThreads[i] = thread(missileHitThread, i);

	} // Ending scope operator, this end a block of code

	//For statement for joining the threads
	for (int i = 0; i < numTargets; i++)
	{ //Starting scope operator, this starts a code block 

		//joinable simply returns a boolean
		if (hitThreads[i].joinable())
		{ //Starting scope operator, this starts a code block

			//STEP 4 WE JOIN IT
			//join says take this thread and run that function
			hitThreads[i].join();

		} // Ending scope operator, this end a block of code
		//else will dislay if thread NOT joined
		else
		{ //Starting scope operator, this starts a code block

			cout << "\n\n*** MISSILE HAS MISSED ***" << i << endl;
		} // Ending scope operator, this end a block of code

	} // Ending scope operator, this end a block of code

	//All couts from here will display what is going on and dialogue
	cout << "\nAll missiles have been launched and have hit their targets.";

	cout << "\n\nWOW every missile was a hit! Good shooting!";
	cout << "\nNow is the time to close the hatches, don't want any birds flying in now!";
	cout << "\nWhenever you are ready, follow the command below.\n\n";

	//Function for pause until user hits a button.
	system("pause");

	cout << "\nInitiating hatch closing...\n\n";


	//Create the thread STEP 2
	thread closingThreads[numThreads];

	for (int i = 0; i < numThreads; i++)
	{ //Starting scope operator, this starts a code block
		//Associate the thread STEP 3 
		closingThreads[i] = thread(closeHatchThread, i);

	} // Ending scope operator, this end a block of code

	//For statement for joining the threads
	for (int i = 0; i < numThreads; i++)
	{ //Starting scope operator, this starts a code block

		//joinable simply returns a boolean
		if (closingThreads[i].joinable())
		{ //Starting scope operator, this starts a code block

			//STEP 4 WE JOIN IT
			//join says take this thread and run that function
			closingThreads[i].join();

		} // Ending scope operator, this end a block of code
		//else will dislay if thread NOT joined
		else
		{ //Starting scope operator, this starts a code block
			cout << "\n\n*** ERROR CLOSING HATCH ***" << i << endl;

		} // Ending scope operator, this end a block of code

	} // Ending scope operator, this end a block of code

	//All couts from here will display whats going on and end the program.
	cout << "\nAll hatches CLOSED.\n" << endl;

	cout << "\nGlad you could join us today and great job hitting those targets!";
	cout << "\nIf you would like to do it again, close and reopen the program!\n\n";

	//Return needed to end the function
	return 0;
} // Ending scope operator, this end a block of code


//Steps to creating threads
/*
create function
create the thread
associate the thread with the function
we join it
then thats it

*/