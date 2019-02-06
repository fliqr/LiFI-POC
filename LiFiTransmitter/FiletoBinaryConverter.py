#============================================
#
#   Hackathon: File to Binary Converter
#
#============================================

def fileBinary():
    fileName = "testfile.txt"
    with open(fileName, "rb") as binary_file:
        text = binary_file.read()
        data = ""
        for x in text:
            x = format(ord(chr(x)), 'b')
            x = "0"*(8-len(x)) + x
            data += x
        return data

x = fileBinary()
print(x)

"""
#Start Bit
GPIO.output(15, GPIO.HIGH)
sleep(0.006)
GPIO.output(15, GPIO.LOW)
sleep(0.006)

#Encode Data
for bit in binary:
	if bit == 1:
		GPIO.output(15, GPIO.HIGH)
		sleep(0.004)
		GPIO.output(15, GPIO.LOW)
		sleep(0.002)
	if bit == 0:
		GPIO.output(15, GPIO.HIGH)
		sleep(0.002)
		GPIO.output(15, GPIO.LOW)
		sleep(0.002)

#Transfer Complete
GPIO.output(15, GPIO.HIGH)
"""
