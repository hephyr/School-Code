import os
import json
import functools
from multiprocessing.dummy import Pool

import requests

def downloadPhoto(url):
    name = url[url.find('photos/') + 7:url.find('/download')] + '.jpg'
    if not os.path.exists(os.path.join('photos', name)):
        dl_res = requests.get(url, allow_redirects=True)
        with open(os.path.join('photos', name), 'wb') as f:
            f.write(dl_res.content)
            print "Downloaded {}".format(name)
    else:
        print "{} already exist!".format(name)


def getUrlList(pages, links):
    url = 'https://api.unsplash.com/photos'
    for page in pages:
        payload = {'page': page,
                   'per_page': '10',
                   'order_by': 'popular',
                   'client_id': os.environ['unsplash_id']}
        r = requests.get(url, params=payload)
        page = json.loads(r.text)
        download_links = []
        for iterm in page:
            download = iterm['links']['download']
            download_links.append(download)
        links += download_links

def main():
    if not os.path.exists('photos'):
        os.mkdir('photos')
    links = list()
    pages = [str(x) for x in range(1, 51)] pool = Pool(10)
    pool.map(functools.partial(getUrlList, links=links), pages)
    pool.close()
    pool.join()
    print "Downloading {} photos...".format(len(links))
    pool = Pool(10)
    pool.map(downloadPhoto, links)
    pool.close()
    pool.join()
    print "Done."


if __name__ == '__main__':
    main()
