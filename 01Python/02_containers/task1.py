import webbrowser

favourite_link = {
    "facebook":"https://www.facebook.com/",
    "instagram":"https://www.instagram.com/",
    "linkedin":"https://www.linkedin.com/",
    "tiktok":"https://www.tiktok.com/",
    "youtube":"https://www.youtube.com/"
}

while True:
    try:
        link = input(f"Enter your desired website from this list {favourite_link.keys()} : ")
        if  link.strip().lower() in favourite_link.keys():
            webbrowser.open_new(favourite_link[link.strip().lower()])
        else :
            print("Enter Valid Website")
        continue
    except KeyboardInterrupt :
        break
