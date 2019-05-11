'use strict';
const osmosis = require('osmosis');
const fs = require('fs');
const converter = require('json2csv');

let response = [];

function getHomePageTrending() {
  return new Promise((resolve, reject) => {

    osmosis 
    
      .get('https://www.danmurphys.com.au/red-wine/all')
      .paginate('//*[@id="results"]/div[2]/div/shop-pagination/div/a[2]/i', 2)
      .set({
        title: '#results > div.row.result-container > div.col-xs-12.col-lg-9 > search-results > div > ul > div > li:nth-child(1) > shop-product-card > div > section > div.product-content.default-content > h2 > a > span.title.overflow',
        grape: '#results > div.row.result-container > div.col-xs-12.col-lg-9 > search-results > div > ul > div > li:nth-child(1) > shop-product-card > div > section > div.product-content.default-content > h2 > a > span.subtitle.overflow',
        PerBottle: '#results > div.row.result-container > div.col-xs-12.col-lg-9 > search-results > div > ul > div > li:nth-child(1) > shop-product-card > div > section > div.product-content.default-content > div > div.wrapper > product-card-view > div > div:nth-child(1) > span.value',
        TwelveBottle: '#results > div.row.result-container > div.col-xs-12.col-lg-9 > search-results > div > ul > div > li:nth-child(1) > shop-product-card > div > section > div.product-content.default-content > div > div.wrapper > product-card-view > div > div:nth-child(2) > span.value'
      })
      .data(res => response.push(res))
      .error(err => reject(err))
      .done(() => resolve(response));
      
      
  });
}


getHomePageTrending().then(res => {
  var jsonstrMinified = JSON.stringify(res); //unformatted
  var jsonstr = JSON.stringify(res, null, 2);  //formatted
  fs.writeFileSync('file-on-disk2.json', jsonstr);

  var fields = ['title', 'grape', 'PerBottle', 'TwelveBottle'];
  var parser = new converter.Parser( fields );
  var csvstr = parser.parse(res);
  fs.writeFileSync('file-on-disk2.csv', csvstr);
});
  

