import static org.junit.Assert.*;
import org.junit.jupiter.api.Test;

class TestSlipperySlot {

	
	//Testing the first rule
	//while no other rules are applied
	//Thus the expected payoff is 1000000
	@Test
	public void testRuleOne() {
		//expected payment is 1000000
		int expectedPayOff = 1000000;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing five same numbers in an integer array
		int[] array = {3,3,3,3,3};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	
	//Testing the second rule
	//while no other rules are applied
	//Thus the expected payoff is 10000
	@Test
	public void testRuletwo() {
		//expected payment is 10000
		int expectedPayOff = 10000;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing four same numbers and one different number
		//in an integer array
		int[] array = {3,3,3,3,7};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	//Testing the third rule
	//while no other rules are applied
	//Thus the expected payoff is 5000
	@Test
	public void testRuleThree() {
		//expected payment is 5000
		int expectedPayOff = 5000;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing three same numbers and two different same numbers
		//in an integer array
		int[] array = {3,3,3,7,7};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	//Testing the fourth rule
	//while no other rules are applied
	//Thus the expected payoff is 100
	@Test
	public void testRuleFour() {
		//expected payment is 100
		int expectedPayOff = 100;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing three same numbers and two different numbers
		//in an integer array
		int[] array = {3,3,3,7,11};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	//Testing the fifth rule
	//while no other rules are applied
	//Thus the expected payoff is 10
	@Test
	public void testRuleFive1() {
		//expected payment is 10
		int expectedPayOff = 10;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing two pairs of same numbers and a different number
		//in an integer array
		int[] array = {3,3,7,7,11};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	//Testing the fifth rule
	//while no other rules are applied
	//Thus the expected payoff is 10
	@Test
	public void testRuleFive2() {
		//expected payment is 10
		int expectedPayOff = 10;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing a pair of same numbers and three different numbers
		//in an integer array
		int[] array = {3,3,7,11,13};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	//Testing the sixth rule
	//while no other rules are applied
	//Thus the expected payoff is 7
	@Test
	public void testRuleSix() {
		//expected payment is 7
		int expectedPayOff = 7;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing five different numbers
		//one of them is 36 which is a square of 6
		int[] array = {3,7,11,13,9};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	//Testing the seventh rule
	//while no other rules are applied
	//Thus the expected payoff is 2
	@Test
	public void testRuleSeven() {
		//expected payment is 2
		int expectedPayOff = 2;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing five different numbers
		//and one 42
		//in an integer array
		int[] array = {3, 5, 7, 11, 42};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	
	//Testing the eighth rule
	//while no other rules are applied
	//Thus the expected payoff is 3
	@Test
	public void testRuleEight() {
		//expected payment is 3
		int expectedPayOff = 3;
		
		//instantiating a new SlipperySlot Object
		SlipperySlot sSlot = new SlipperySlot();
		//Storing five different numbers
		//and 4 which is the second power of 2
		//in an integer array
		int[] array = {3, 5, 7, 11, 8};
		//Storing the payoff of the slippery machine in an integer
		int slipperyPayOff = sSlot.payOff(array);
		
		//Checking if the slippery machine's payoff
		//matches to the expected payoff according to the rules
		assertEquals(expectedPayOff, slipperyPayOff);
	}
	
	
}