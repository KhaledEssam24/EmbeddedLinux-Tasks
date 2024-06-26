import webbrowser
import time 
import os 
from gtts import gTTS
import speech_recognition
import playsound

class alexa():
    def __init__(self) -> None:
        self.recognizer = speech_recognition.Recognizer()

    def record(self):
        with speech_recognition.Microphone() as microphone:
            self.recognizer.adjust_for_ambient_noise(microphone)
            self.raw_speech = self.recognizer.listen(microphone)

    def recognize_record(self):
        try:
            text = self.recognizer.recognize_google(self.raw_speech,language='ar-EG')
            print(text)
        except :
            text= ""
            print("I couldn't Understand!")
        
        return text

    def speak(self,text1):
        tts = gTTS(text=text1,lang='ar',slow=False)
        tts.save('play.mp3')
        playsound.playsound('play.mp3')
        os.remove('play.mp3')

alexa1 = alexa()

alexa1.record()

alexa1.speak(alexa1.recognize_record())
