int led = 13;

unsigned long recording[][2] = 
{
{4,50},
{1124,51},
{1554,52},
{1712,52},
{1874,52},
{2013,52},
{3010,51},
{3495,52},
{3647,52},
{3824,52},
{3961,52},
{4909,51},
{5370,52},
{5529,52},
{5706,52},
{5879,52},
{6833,51},
{7769,49},
{8731,52},
{9193,51},
{9366,51},
{9533,51},
{9697,51},
{10656,52},
{11529,51},
{12586,52},
{13036,51},
{13206,51},
{13371,51},
{13531,51},
{14521,52},
{15495,51},
{16423,52},
{16906,51},
{17066,51},
{17239,51},
{17404,51},
{18333,52},
{19334,51},
{20282,52},
{20707,51},
{20876,51},
{21043,51},
{21225,51},
{22178,52},
{23145,50},
{24103,52},
{25051,51},
{26037,52},
{26980,51},
{27934,52},
{28921,51},
{29841,52},
{30835,51},
{31824,52},
{32761,51},
{33718,52},
{34676,51},
{35663,52},
{36591,51},
{37561,52},
{38536,51},
{38945,51},
{39280,51},
{39568,51},
{39889,51},
{40197,51},
{40441,52},
{40838,52},
{41167,52},
{41444,52},
{41775,52},
{42112,52},
{42357,53},
{42744,53},
{43087,53},
{43357,53},
{43689,53},
{44021,53},
{44265,54},
{44647,54},
{45023,54},
{45273,54},
{45620,54},
{45941,54},
{46208,55},
{46594,55},
{46932,55},
{47198,55},
{47541,55},
{47871,56},
{48142,56},
{48478,56},
{48836,56},
{49106,56},
{49421,56},
{49742,57},
{50030,57},
{50365,57},
{50712,57},
{50960,57},
{51322,57},
{51621,57},
{51915,57},
{52261,57},
{52611,57},
{52873,57},
{53764,50},
{54791,51},
{55788,52},
{56776,52},
{57716,51},
{58668,52},
{59599,51},
{60551,52},
{61486,51},
{62476,52},
{63408,51},
{64440,52},
{65363,51},
{66345,52},
{67293,51},
{68284,52},
{69195,51},
{70195,52},
{71147,51},
{72149,52},
{73072,51},
{74050,52},
{74981,51},
{75968,52},
{76918,51},
{77910,52},
{79836,53},
{80759,53},
{81697,53},
{82683,53},
{83662,53},
{84575,53},
};

void setup() {
  Serial.begin(9600);
  
  // initialize the digital pin as an output.
  for (byte p=0; p<10; p++)
  pinMode(2+p, OUTPUT);

  delay(2000); // wait for Hari to start the Processing sketch that plays the mp3 when this sketch sends "0" via COM port.
  Serial.print('0');
  delay(300); // if Arduino is late, lower this number

  unsigned long beginningOfTime;
  for (int index = 0; index < sizeof(recording) / sizeof(unsigned int) / 2; index++)
  {
    if (index==0)
    {
      // We start time upon first note.
      beginningOfTime = millis();
      
    }
    else
    {
      //-- Wait till recording[i] time or after --
      while ( (millis() - beginningOfTime) < recording[index][0] ) delay(100);
    }

    //-- Play the char --
    int whichLed = recording[index][1] - '1' + 2; // Subtract char relative to '1' on the PC keyboard, add 2 because first led starts at D2.
    //whichLed = 2;
    digitalWrite(whichLed, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);                 // wait for a bit
    digitalWrite(whichLed, LOW);    // turn the LED off by making the voltage LOW
  }
}

void loop() {
  // nothing to see here...
}
