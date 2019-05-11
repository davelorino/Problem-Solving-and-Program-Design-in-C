const osmosis = require('osmosis');

function getOpenGraphMeta() {
  return new Promise((resolve, reject) => {
    let response;
    
    osmosis 
    
    .get('https://steemit.com')
    .find('head')
    .set({
      title: "meta[property='og:title'@content",
      description: "meta[property='og:description']@content"
    })
    .data(res => response = res)
    .error(err => reject(err))
    .done(() => resolve(response));
  });
}

getOpenGraphMeta().then(res => {
  console.log(res);
});

function getHomePageTrending() {
  return new Promise((resolve, reject) => {
    let response = [];
    
    osmosis 
    
      .get('https://steemit.com')
      .find('.PostsList__summaries > li')
      .set({
        title: 'h2',
        summary: '.PostSummary__body'
      })
      .data(res => response.push(res))
      .error(err => reject(err))
      .done(() => resolve(response));
  });
}

getHomePageTrending().then(res => {
  console.log(res);
});





