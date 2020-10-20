# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).

#These tests will go from 15 to 0 in binary and depending how many 0'are in each binary number
#will determine how many free spots the parking lot will have at all possible scenarios
tests = [ 
     {'description': 'This test will run first.', #extreme case where PORTA and PORTC have max weight but nothing on PORTB
     'steps': [
         {'inputs': [('PINA',0xFF),('PINB',0x00),('PINC',0xFF)],'iterations': 1} ], 'expected': [('PORTD',0xF9)],
    },
     {'description': 'This test will run second.',#extreme case where nobody is in any seat making the total weight 0 kg
      'steps': [ 
        {'inputs': [('PINA',0x00),('PINB',0x00),('PINC',0x00)], 'iterations': 1} ], 'expected': [('PORTD',0x00)],       
     },
    {'description': 'This test will run third.',#middle case where people are on board but no rules are broken
      'steps': [
        {'inputs': [('PINA',0x3F),('PINB',0x0F),('PINC',0xF0)], 'iterations': 1} ], 'expected': [('PORTD',0xFA)],
    },
    
    ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['main::PINA,PINB,PINC','PORTD']
#reference statement
 # {'inputs': [('PINA',0x0E)], 'iterations': 1, 'expected': [('PORTC',0x01)]}

