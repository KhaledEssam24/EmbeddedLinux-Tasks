import webbrowser
import time 
import os 
from gtts import gTTS
import speech_recognition
import playsound
import pyautogui
import sys

sys.path.insert(0, '../02_containers')
from vs_extension_installation import open_vs_code

class alexa():
    def __init__(self) -> None:
        self.recognizer = speech_recognition.Recognizer()

    def record(self):
        with speech_recognition.Microphone() as microphone:
            print("Listening............")
            self.recognizer.adjust_for_ambient_noise(microphone)
            self.raw_speech = self.recognizer.listen(microphone)

    def recognize_record(self):
        try:
            text = self.recognizer.recognize_google(self.raw_speech,language='ar-EG')
            print(text)
        except :
            text= ""
            print("Waiting .......")
        return text

    def speak(self,text1):
        tts = gTTS(text=text1,lang='ar',slow=False)
        tts.save('play.mp3')
        playsound.playsound('play.mp3')
        os.remove('play.mp3')


    def response(self,text):
        if(("وقت" in text ) or ( "ساعة" in text) or ( "ساعه" in text) or ( "تاريخ" in text) or ( "نهارده" in text)):
            self.speak(time.ctime())

        elif("فيس" in text):
            self.speak('فتح الفيس بوك الان')
            webbrowser.open_new("https://www.facebook.com/")

        elif("يوتيوب" in text):
            self.speak('فتح اليوتيوب الان')
            webbrowser.open_new("https://www.youtube.com/")

        elif("انستا" in text):
            self.speak('فتح الانستغرام الان')
            webbrowser.open_new("https://www.instagram.com/")

        elif("توك" in text):
            self.speak('فتح التيك توك الان')
            webbrowser.open_new("https://www.tiktok.com/")

        elif("كود" in text):
            self.speak('الان vs code فتح')
            open_vs_code()

alexa1 = alexa()

while True:
    try:
        alexa1.record()
        alexa1.response(alexa1.recognize_record())
    except KeyboardInterrupt:
        print("Existing .....")
        break
