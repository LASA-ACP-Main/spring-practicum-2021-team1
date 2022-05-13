import gdown

url = "https://drive.google.com/uc?export=download&id=1JL9qzg3_hOiRnM7NGx-aNFR8PX9WokaT"
output = "file.csv"
gdown.download(url, output)

