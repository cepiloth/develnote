from wordcloud import WordCloud
import matplotlib.pyplot as plt
#matplotlib inline

import numpy as np
from PIL import Image

if "__main__":

    #mask image 생성
    alice_mask = np.array(Image.open("alice.jfif"))
    alice_color = np.array(Image.open("alice_color.png"))
    #단어가 포함되어 있는 txt 오픈
    text = open('constitution.txt').read()

    wordcloud = WordCloud(background_color="white", max_words=2000, max_font_size=40, mask=alice_color
                            , random_state=42)
    wordcloud.generate(text)


    #wordcloud = WordCloud(max_font_size=40).generate(text)
    #wordcloud.words_ #워드클라우드 내부를 확인하고 싶을때

    plt.figure(figsize=(12, 12))
    #plt.imshow(wordcloud, interpolation='bilinear')

    #color 영상의 색상 그대로 가져오기
    from wordcloud import ImageColorGenerator
    image_colors = ImageColorGenerator(alice_color)
    plt.imshow(wordcloud.recolor(color_func=image_colors), interpolation='bilinear')

    #masking 처리 없이 wordcloud 를 보여줄때
    #plt.imshow(wordcloud, interpolation='bilinear')
    plt.axis("off")
    plt.show()