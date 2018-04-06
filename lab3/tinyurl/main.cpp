//
// Created by Asia on 2018-04-06.
//

#include "TinyUrl.h"


int main(){


    std::vector<std::string> zbior_adresow_url
            {"https://support.google.com/a/answer/3299041?hl=pl","https://stackoverflow.com/questions/742013/how-to-code-a-url-shortener","https://www.youtube.com/watch?v=aDXjubGK0jU",
             "https://leetcode.com/problems/encode-and-decode-tinyurl/description/","http://planzajec.eaiib.agh.edu.pl/view/timetable/334?date=2018-04-09",
             "https://www.google.pl/search?q=mis&oq=mis&aqs=chrome..69i57j69i60l3j0l2.230j0j4&sourceid=chrome&ie=UTF-8","https://www.agh.edu.pl/",
             "https://pl.wikipedia.org/wiki/Akademia_G%C3%B3rniczo-Hutnicza_im._Stanis%C5%82awa_Staszica_w_Krakowie","https://www.google.pl/search?q=Andrzej+Czerwi%C5%84ski&stick=H4sIAAAAAAAAAONgFuLUz9U3MDEtM81SAjPTzApzDbSEQvMyy1KLijNLKkPyHXNKc_MyAXDZ2YMsAAAA&sa=X&ved=0ahUKEwi8-_GQiqbaAhUCNxQKHQ8VAyYQxA0I7AEwIg&biw=1396&bih=646",
             "http://www.dziennikpolski24.pl/artykul/3901397,andrzej-czerwinski-prezydent-posel-minister-skarbu-wideo,id,t.html","https://www.google.pl/search?q=agh&tbm=isch&source=iu&ictx=1&fir=yfELYlu6tEosYM%253A%252CQlaofhkJoLZSlM%252C_&usg=__u90BJ_7PBmUUNbk2vAGUSbKIfkg%3D&sa=X&ved=0ahUKEwi8-_GQiqbaAhUCNxQKHQ8VAyYQ9QEIaTAK#imgrc=yfELYlu6tEosYM:",
             "https://allegro.pl/dzial/dom-i-ogrod","http://cpp0x.pl/artykuly/?id=47","https://allegro.pl/kategoria/kosiarki-kosiarki-spalinowe-85213?stan=nowe&offerTypeBuyNow=1&producent=NAC&order=qd",
             "http://www.1-lo.pl/","http://www.1-lo.pl/news/srebrna-tarcza-2017","http://www.echodnia.eu/swietokrzyskie/studniowki/galerie/wloszczowa/art/8942789,i-liceum-ogolnoksztalcace-im-genwladyslawa-sikorskiego-we-wloszczowie,id,t.html"
            };

    unique_ptr<tinyurl::TinyUrlCodec> struktura = tinyurl::Init();

    for (auto url : zbior_adresow_url) {


        struktura->mapka.emplace(tinyurl::Encode(url, &struktura), url);

    }

    for(const auto &n : struktura->mapka) {
        std::cout << "To jest hash " << n.first << " dla " <<n.second<<std::endl;
    }
    return 0;
}
