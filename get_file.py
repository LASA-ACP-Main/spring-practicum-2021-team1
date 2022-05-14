import gdown

print('Enter teacher csv file url:')
sharing_url = input()

#sharing_url = "https://drive.google.com/file/d/1JL9qzg3_hOiRnM7NGx-aNFR8PX9WokaT/view?usp=sharing"

file_id = ""
for i in range(len(sharing_url)):
    if i > 31:
        if not sharing_url[i] == "/":
            file_id += sharing_url[i]
        else:
            break

downloadable_url = "https://drive.google.com/uc?export=download&id=" + file_id; 
downloadable_url; 

print(downloadable_url)
output = "file.csv"
gdown.download(downloadable_url, output)

