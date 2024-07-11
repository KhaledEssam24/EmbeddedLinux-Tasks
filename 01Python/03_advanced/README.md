## These are Advanced session tasks

Before getting started you should run the following commands

```
sudo apt-get install portaudio19-dev
```

- Alexa is to provide you a voice assistant it could open vscode ,youtube,tiktok,instagram,facebook and other features in the comming days
- Azan notification is to send you a notification when the pray time comes based on your latitude ,longitude
- Doxygen is to parse html output from doxygen and then store it in an csv file
- GPIO is to generate gpio.c file with init ,write and read functions based on user choice

To get access to Alexa-gpt2 you have to add transformers dependencies 
```
pip install --upgrade git+https://github.com/huggingface/transformers.git accelerate datasets[audio]
```

To run any file here please clone this repo and then navigate to the right place where you could find requirements.txt file 
then install dependiencies by running this command 

```
python3 -m pip install -r requirements.txt
```


To run anyfile run command 

```
python3 <FileName>.py
```

