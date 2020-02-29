package test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import junit.framework.Assert;
import main.Count;

class CounterTest {

	@Test
	void test() {
		Count cnt=new Count();
		int output = 0;
		output = cnt.countA("Sohanur Rahman");
		assertEquals(3,output);
				
	}

}
