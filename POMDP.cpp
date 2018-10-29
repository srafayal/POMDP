// POMDP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<string>
void GetAlphaVector(int no_actions, int no_states, float q[3][2], float p[3][2][2], float r[3][2][2], float pi[2], int t, int previous_index  );
void GetAlphaVectorIndex(int no_actions, int no_states, float q[3][2], float p[3][2][2], float r[3][2][2], float pi[2], int t);
void GetNewBelief(int no_actions, int no_states, float pi[2], float p[3][2][2], float r[3][2][2]);


static int alpha[2][3][2]  = {};
 
int main()
{
	// The discount factor used in value iteration
	int GAMMA = 1;

	int max_time = 2;
	int listen_count = 0;
	// The states of the Game
	std::string states[] = { "left", "right" };
	int no_states = 2;
	// The actions available to the player
	std::string actions[] = { "listen", "left", "right" };
	int no_actions = 3;
	float p[3][2][2] = {
					 { {1.0, 0.0}, {0.0, 1.0} },
					 { {.5, .5}, {.5, .5} },
					 { {.5, .5}, {.5, .5} }
	};

	float r[3][2][2] = {
					 { {0.85, 0.15}, {0.15, 0.85} },
					 { {.5, .5}, {.5, .5} },
					 { {.5, .5}, {.5, .5} }
	};

	float w[3][2][2] = {
					 { {-1,-1}, {-1,-1} },
					 { {-100, -100}, {10,10} },
					 { {10,10}, {-100,-100} }
	};

	float pi[2] = { 0.5, 0.5 };
	float q[3][2]= {};//expected_reward
	float sum = 0.0;
	for (int a = 0; a < no_actions; a++)
	{
		for (int i = 0; i < no_states; i++)
		{
			sum=0;
			for (int j = 0; j < no_states; j++)
			{
				for (int th = 0; th < 2; th++)
				{

					sum = sum + p[a][i][j] * r[a][j][th] * w[a][i][th];
				}
			}
			q[a][i] = sum;
		}
	}
	GetNewBelief(no_actions, no_states, pi , p , r );
	GetAlphaVector(no_actions, no_states, q , p , r , pi , 0,  0);
	std::cout << "Hello World!\n";
	//std::cout << "Line 1 - Value of (int)a is :" << listen_count << "\n";
}
void GetNewBelief(int no_actions, int no_states, float pi[2], float p[3][2][2], float r[3][2][2])
{
	float sum_Denominator = 0.0;
	for (int a = 0; a < no_actions; a++)
	{
		for (int i = 0; i < no_states; i++)
		{
			for (int j = 0; j < no_states; j++)
			{
				for (int th = 0; th < 2; th++)
				{
					sum_Denominator = sum_Denominator + pi[i] * p[a][i][j] * r[a][j][th];
				}
			}
		}

		float update_pi = 0.0;
		float numerator = 0.0;
		for (int j = 0; j < no_states; j++)
		{
			numerator = 0;

			for (int i = 0; i < no_states; i++)
			{

				for (int th = 0; th < 2; th++)
				{
					numerator = numerator + pi[i] * p[a][i][j] * r[a][j][th];
				}

			}
			update_pi = numerator / sum_Denominator;
			std::cout << std::to_string(update_pi) + " \n";
		}

	}
}

void GetAlphaVector(int no_actions, int no_states, float q[3][2], float p[3][2][2], float r[3][2][2], float pi[2],  int t,int previous_index=0)
{
	float sum = 0.0;
	for (int a = 0; a < no_actions; a++)
	{
		for (int i = 0; i < no_states; i++)
		{
			sum = q[a][i];
			if (t > 0)
			{
				for (int j = 0; j < no_states; j++)
				{
					for (int th = 0; th < 2; th++)
					{
						//sum = sum
					}
				}
			}
			alpha[t][a][i] = sum;
		}
	}

	return  ;
}

void GetAlphaVectorIndex(int no_actions, int no_states, float q[3][2], float p[3][2][2], float r[3][2][2], float pi[2], int t )
{
	for (int a = 0; a < no_actions; a++)
	{
		for (int i = 0; i < no_states; i++)
		{
		}
	}

	return;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
