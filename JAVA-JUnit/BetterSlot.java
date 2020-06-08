import java.util.Random;

public class BetterSlot {

	//pullTheLever function implementation
	public int[] pullTheLever() {
		//returning integer array
		int[] values = {-1,-1,-1,-1,-1};
		Random randy = new Random();
		//integer i limit to 5 since we only need five values
        for (int i = 0; i < 5; i++) {
            values[i] = randy.nextInt(50) + 1;
        }
        return values;
    }//END int[] pullTheLever()
		
	//payOff function implementation
	public int payOff(int[] array) {
		int count = 0;
		int expectedPayOff = 0;

		//nested for-loops to count how many times
		//each number faces same number as itself
		//This also compares the number itself
		for(int i = 0; i <= 4; i++)
		{
			for(int j = 0; j < 5; j++)
			{
				if(array[i] == array[j])
				{
					count++;
				}
			}//END for-loop for j
		}//END for-loop for i
		
		//If all five numbers are the same,
		//then each number encounters the same
		//number five times, thus 5*5 = 25
		if(count == 25)
		{
			expectedPayOff += 1000000;
		} 
		//If all four numbers are the same and one is different,
		//then you obtain count of 17 when each number is compared to
		//all five numbers including itself
		else if( count == 17)
		{
			expectedPayOff += 10000;
		} 
		//If all three numbers are the same and two are different but the same,
		//then you obtain count of 13 when each number is compared to
		//all five numbers including itself
		else if(count == 13)
		{
			expectedPayOff += 5000;
		}
		//If all three numbers are the same and two are different,
		//then you obtain count of 11 when each number is compared to
		//all five numbers including itself
		else if(count == 11)
		{
			expectedPayOff += 100;
		} 
		//If all two numbers are the same and three are different,
		//then you obtain count of 7 when each number is compared to
		//all five numbers including itself
		//However this case also accounts for the case when 
		//there are two pairs of equal numbers
		//which obtains count of 9
		else if(count == 9 || count ==  7)
		{
			expectedPayOff += 10;
		} 
		//Else the payOff is zero
		else 
		{
			expectedPayOff += 0;
		}
		
		
		
		//This checks for if there is any number that is 
		//a square of an integer
		boolean squareTrue = false;
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				if(array[i] == Math.pow(j, 2))
				{
					squareTrue = true;
				}
			}//for j
		}//for i
		if(squareTrue == true)
		{
			expectedPayOff += 7;
		}
		
		
		
		//This checks for if there is any 42
		boolean fortytwoTrue = false;
		for(int i = 0; i < 5; i++)
		{
			if(array[i] == 42)
			{
				fortytwoTrue = true;
			}

		}//for i
		if(fortytwoTrue == true)
		{
			expectedPayOff += 2;
		}
		
		
		
		//This checks for if there is any number
		//that is power of two
		boolean powerOfTwo = false;
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				if(array[i] == Math.pow(2, j))
				{
					powerOfTwo = true;
				}
			}//for j
		}//for i
		if(powerOfTwo == true)
		{
			expectedPayOff += 3;
		}
		
		//returns expectedPayOff
		return expectedPayOff;
	}//END int payOff
}//END of class