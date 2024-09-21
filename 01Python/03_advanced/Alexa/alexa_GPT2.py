import webbrowser
import time
import os
from gtts import gTTS
import speech_recognition as sr
import playsound
import sys
import logging

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

class Alexa:
    def __init__(self) -> None:
        self.recognizer = sr.Recognizer()

    def record(self):
        with sr.Microphone() as microphone:
            logging.info("Listening...")
            self.recognizer.adjust_for_ambient_noise(microphone)
            self.raw_speech = self.recognizer.listen(microphone)

    def recognize_record(self):
        try:
            text = self.recognizer.recognize_google(self.raw_speech, language='ar-EG')
            logging.info(f"Recognized: {text}")
        except sr.UnknownValueError:
            text = ""
            logging.warning("Could not understand the audio")
        except sr.RequestError:
            text = ""
            logging.error("Could not request results; check your network connection")
        return text

    def speak(self, text):
        tts = gTTS(text=text, lang='ar', slow=False)
        tts.save('play.mp3')
        playsound.playsound('play.mp3')
        os.remove('play.mp3')

    def response(self, text):
        pass

def main():
    alexa = Alexa()
    while True:
        try:
            alexa.record()
            text = alexa.recognize_record()
            alexa.response(text)
        except KeyboardInterrupt:
            logging.info("Exiting...")
            break

if __name__ == "__main__":
    main()
