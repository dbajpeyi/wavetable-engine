
#ifndef wavetable_h
#define wavetable_h

#define TABLE_LENGTH 512
#define CONCERT_A_FREQ 440.000000
#define SEMITONE_RATIO pow(2.0, 1.0 / 12.0)
#define PI 3.14159265358979323846264
#define NUM_CHANNELS 1
#define SAMPLE_RATE 48000.0

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  sine = 0,
  saw,
  custom,
  square,
  triangle,
} WaveType;

float sawtooth(float phase);

void generateWaveTable(float* waveTable, WaveType waveType);

float* readWaveTableFromFile(const char* filePath, int* tableLength);

float lookupTable(float* waveTable, float index, int tableLength);

void writeCustomWaveform(float* waveTable, int tableLength,
                         const char* outfile);

typedef struct {
  float left;
  float right;
} StereoPanPosition;

/**
 * @brief Get the Frequency From Midi Note.
 * The value of the midi note can be between the integers 0-127 which is the
 * midi standard
 * @param midiNote
 * @return float
 */
float getFrequencyFromMidiNote(int midiNote);

/**
 * @brief Utility function to calculate base C frequency based on CONCERT_A_FREQ
 *
 * @return float
 */
float getC0Frequency();

/**
 * @brief Utility function to get a midi note From freq in Hz
 *
 * @param freq
 * @return int
 */
int getMidiNoteFromFreq(float freq);

StereoPanPosition getStereoPanPosition(float position);

#ifdef __cplusplus
}
#endif

#endif
