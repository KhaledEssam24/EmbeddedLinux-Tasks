import pyautogui
import time 
import os

path = os.path.dirname(os.path.realpath(__file__))

extensions={
    'clangd': '/clangd.png',
    'c++ helper' : '/helper.png',
    'c++ testmate' : '/testmate.png',
    'cmake tools' : '/cmaketools.png',
    # cmake should be installed by default while installing cmake tools
    # 'cmake' : '/cmake.png'
}

def open_vs_code()->None:
    pyautogui.hotkey('win')
    pyautogui.write('visual',interval=0.2)
    pyautogui.hotkey('enter')   
    time.sleep(5)

def disp_extension()->None:
    point = None
    while point is None:
        try:
            point = pyautogui.locateOnScreen(path + '/screenshots' + '/extension.png',confidence=0.7)   
        except pyautogui.ImageNotFoundException:
            print(f"Image  Not Found")
    pyautogui.click(pyautogui.center(point))

def install_extension():
    for key,value in extensions.items():
        time.sleep(0.5)
        pyautogui.hotkey('ctrl', 'a')
        time.sleep(0.5)
        pyautogui.hotkey('backspace')
        time.sleep(0.5)

        point = None
        pyautogui.write(key,interval=0.2)
        pyautogui.hotkey('enter')
        time.sleep(2)

        while point is None:
            try:
                point = pyautogui.locateOnScreen(path + '/screenshots' + value,confidence=0.7)   
            except pyautogui.ImageNotFoundException:
                print(f"Image {value} Not Found")

        pyautogui.click(point[0]+300,point[1]+50)
        time.sleep(2)
        pyautogui.click(point[0]+150,point[1]-25)

def main():
   open_vs_code()
   disp_extension()
   install_extension()

if __name__ == '__main__':
   main()