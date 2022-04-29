import gdown

url = "https://docs.google.com/spreadsheets/d/1By9expl3fr87AH2S9Hd8hymW4ZzDtrZp5msPJoSSfac/export?format=csv"
output = "practicum_responses.csv"
gdown.download(url, output)


