# 24-Bit-Audio-Steganography
This hides an arbitrary file within a 24 bit WAV file, with no audible defects to the human ear.
It can also extract an arbitrary file hidden inside a 24 bit WAV.

Should work for any sample rate, up to 192 KHz.

Upon executing, type 'E' for encoding and 'D' for decoding.

Encoding:
  1. Gather the executable, a 24 bit audio file, and an arbitrary file to be encoded in one folder.
  2. Open the .exe.
  3. Type and enter 'E'
  4. Type in and enter the file name of the 24 bit WAV.
  5. Type in and enter the file name of the file to be hidden.
  6. A file named 'hiden.wav' will be generated. That is the new 24 bit WAV file which sounds identical to the input one.

**NOTE FOR ENCODING: Files to be hidden must be less than 1/3 of the size of the 24 bit WAV.**

Decoding:
  1. Gather the executable and the encoded 24 bit file in one folder.
  2. Open the .exe.
  3. Type in and enter 'D'.
  4. Type in and enter the file name of the encoded WAV.
  5. Type in and enter the desired file name (anything you want) for the file to be extracted, including the file extension.
  6. A new file will be generated, with the name matching that of which was entered in the previous step.

**NOTE FOR DECODING: As of now, the extracted file will have a size of approximately 1/3 the 24 bit WAV no matter how small it was before it was encoded into the WAV. Aside from taking up more storage, certain kinds of files may not function correctly (e.g. .zip files). Most kinds of files work fine, however. 
Use at your own risk.**
