#define MINSEQ 0
#define MAXSEQ (sizeof(sequences)/sizeof(sequences[0]))
#define ENDSEQ (0x8080)
#define LOOPTIME  5

// these are the lists of the valves to open in each sequence. So sequence 1 opens valves 1-4
// for 3 consecutive 400ms periodsfollowed by no valves for 4 periods.
// sequnce 4 does the same but using only valve 5, etc.
// the sequences repeat when they reach the end.

// bottom 8 bits (5 used) control the top valve, inflating via the one-way valve
// top 8 bits (5 used) control the bottom valve at low flow rate but permitting deflation
//
// top closed  bottom closed     output is open to exhaust via bottom valve  
// top closed  bottom open       
// top open    bottom closed     output is connected to source via one-way valve but exhausting through bottom valve
// top open    bottom open       output is sourced by both high-flow top valve and low-flow bottom valve  

#define SPIKY  0b10000
#define PADS1  0b0001
#define PADS2  0b0010
#define PADS3  0b0100
#define PADS4  0b1000
#define PADSALL  (PADS1|PADS2|PADS3|PADS4)
#define PADSH1   (PADS2|PADS4)
#define PADSH2   (PADS1|PADS3)

// open the main valve (no non-return)
#define MAIN(x) ((x)<<8)
// open both valves
#define BOTH(x) ((x)|MAIN(x))

struct step { uint16_t bitmask; int interval; };
struct step seq1[] = { 
  {MAIN(PADSALL), 12000},
  {0, 15000},
  {MAIN(PADSALL), 12000},
  {0, 15000},
  {MAIN(PADSALL), 12000},
  {0, 20000},
  {ENDSEQ,0} };
struct step seq2[] = { 
  {BOTH(PADSALL), 9000},
  {0, 1000},
  {BOTH(PADSH1), 1000},
  {0, 1000},
  {BOTH(PADSH2), 1000},
  {0, 1000},
  {BOTH(PADSH1), 1000},
  {0, 1000},
  {BOTH(PADSH2), 1000},
  {0, 1000},
  {BOTH(PADSH1), 1000},
  {0, 1000},
  {BOTH(PADSH2), 1000},
  {0, 1000},
  {BOTH(PADSH1), 1000},
  {0, 1000},
  {BOTH(PADSH2), 1000},
  {0, 12000},
  {ENDSEQ,0} };
struct step seq3[] = { 
/*
  {BOTH(PADS1),  3000},
  {BOTH(PADS1|PADS2),  2000},
  {BOTH(PADS2|PADS4),  4000},
  {BOTH(PADS2|PADS3|PADS4),  1500},
  {BOTH(PADS3|PADS4),  1500},
  {BOTH(PADS3),        1000},
  {BOTH(PADS1|PADS3),  3000},
  {BOTH(PADS1),  3000},
*/

  {BOTH(PADS1),  4000},
  {BOTH(PADS1|PADS2), 2000},
  {BOTH(PADS2), 2000},
  {BOTH(PADS2|PADS4), 2000},
  {BOTH(PADS4), 2000},
  {BOTH(PADS3|PADS4), 2000},
  {BOTH(PADS3), 2000},
  {BOTH(PADS1),  4000},
  {BOTH(PADS1|PADS2), 2000},
  {BOTH(PADS2), 2000},
  {BOTH(PADS2|PADS4), 2000},
  {BOTH(PADS4), 2000},
  {BOTH(PADS3|PADS4), 2000},
  {BOTH(PADS3), 2000},
  {BOTH(PADS1),  4000},
  {BOTH(PADS1|PADS2), 2000},
  {BOTH(PADS2), 2000},
  {BOTH(PADS2|PADS4), 2000},
  {BOTH(PADS4), 2000},
  {BOTH(PADS3|PADS4), 2000},
  {BOTH(PADS3), 2000},
  
  {0,  20000},
  {ENDSEQ,0} };
struct step seq4[] = { 
  {BOTH(SPIKY), 10000},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {0,50},
  {MAIN(SPIKY), 200},
  {BOTH(SPIKY), 10000},
  {MAIN(SPIKY), 2000},
  {0, 12000},
  {ENDSEQ,0} };
struct step seq5[] = { 
  {BOTH(SPIKY), 3000},
  {0, 1000},
  {BOTH(SPIKY), 1000},
  {0, 1000},
  {BOTH(SPIKY), 1000},
  {0, 1000},
  {BOTH(SPIKY), 1000},
  {0, 1000},
  {BOTH(SPIKY), 1000},
  {0, 1000},
  {BOTH(SPIKY), 1000},
  {0, 1000},
  {BOTH(SPIKY), 1000},
  {0, 1000},
  {BOTH(SPIKY), 1000},
  {0, 1000},
  {BOTH(SPIKY), 1000},
  {0, 20000},
  {ENDSEQ,0} };

// the button steps through the choice of sequences in this list

struct step *sequences[] = { seq1, seq2, seq3, seq4, seq5 };


void setup() {
  // 
  Serial.begin(115200);

  // set output drivers and turn all off
  // top ports D2..D7
  pinMode(2,OUTPUT); digitalWrite(2,0);
  pinMode(3,OUTPUT); digitalWrite(3,0);
  pinMode(4,OUTPUT); digitalWrite(4,0);
  pinMode(5,OUTPUT); digitalWrite(5,0);
  pinMode(6,OUTPUT); digitalWrite(6,0);
  pinMode(7,OUTPUT); digitalWrite(7,0);
  // bottom ports A5..A0
  pinMode(A5,OUTPUT); digitalWrite(A5,0);
  pinMode(A4,OUTPUT); digitalWrite(A4,0);
  pinMode(A3,OUTPUT); digitalWrite(A3,0);
  pinMode(A2,OUTPUT); digitalWrite(A2,0);
  pinMode(A1,OUTPUT); digitalWrite(A1,0);
  pinMode(A0,OUTPUT); digitalWrite(A0,0);

  pinMode(10,INPUT_PULLUP);
  pinMode(12,OUTPUT);digitalWrite(12,0);
  pinMode(11,OUTPUT);digitalWrite(11,1);

  // led off
  pinMode(13,OUTPUT);digitalWrite(13, 0);
}

void loop() {
  static long timer = -1;
  static int seq = MINSEQ, lastseq = MAXSEQ;
  static int index = 0;

  // load initial timer
  if (timer < 0)
    timer = sequences[seq][index].interval;

     

  // output current state. This is locked around ports 2-8 .. should have a map for those really.
  int port, mask;
  for (port = 2, mask = 1; port < 8; ++port, mask <<= 1) {
    digitalWrite(port, ((sequences[seq])[index].bitmask & mask) ? 1  :0);
  }
  for (port = A5, mask = 0x100; port >= A0; --port, mask <<= 1) {
    digitalWrite(port, ((sequences[seq])[index].bitmask & mask) ? 1  :0);
  }

  if ((timer-=LOOPTIME) <= 0) {

    if (sequences[seq][++index].bitmask == ENDSEQ) {
      lastseq = seq;
      //do {
      // seq = random(MINSEQ, MAXSEQ);
      // } while (seq == lastseq);
      if (++seq >= MAXSEQ)
        seq = 0;
      index = 0;

    }
    timer = sequences[seq][index].interval;

    if (1)
    {   
      //Serial.print("debounce ");
      //Serial.print(debounce);

      Serial.print(" sequence ");
      Serial.print(seq+1);

      Serial.print(" index ");
      Serial.print(index);

      Serial.print(" mask ");
      Serial.print(((sequences[seq])[index].bitmask & 0x3f00) >> 8, HEX);
      Serial.print(" ");
      Serial.print(((sequences[seq])[index].bitmask & 0x3f), HEX);

      //Serial.print(" last seq ");
      //Serial.print(lastseq+1);

      Serial.println();
    }  

  }

  // establish loop time to control debounce and sequence timing
  delay(LOOPTIME);


}

