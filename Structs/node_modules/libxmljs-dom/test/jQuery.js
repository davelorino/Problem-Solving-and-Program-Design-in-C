var libxmljs = require('../index');
var fs = require('fs');

var doc = libxmljs.parseHtml(fs.readFileSync(__dirname+'/css2xpath.html'));
doc.location = 'http://example.com/test/testing?test=true';

doc.defaultView.eval(libxmljs.jQuery);
var $ = doc.defaultView.$;

module.exports.select = function(assert) {
    assert.ok($('#only').length === 1)
    assert.ok($('.only').length === 1)
    assert.ok($('li[only="true"]').length === 1)
    assert.done();
}
