var libxmljs = require('../index');
var consoleLog = console.log;

module.exports.new = function(assert) {
    var window = new libxmljs.Window();
    assert.ok(window.document);
    assert.ok(window.self === window);
    assert.ok(window.parent === window);
    assert.ok(window.top === window);
    assert.ok(window.window === window);

    // ensure that console.log has been defined
    assert.ok(console.log !== undefined)

    assert.done();
}

module.exports.lambdaEnvironment = function(assert) {
	// simulate us being in a AWS lambda environment
	process.env.AWS_EXECUTION_ENV = 'AWS_Lambda_nodejsX.Y'
	
	// console.log is overwritten on each lambda run, preventing
	// ability to overwrite causes aws lambda to fail. ensure
	// that this does not fail in lambda environment.
	assert.doesNotThrow(function() {
		'use strict'
		var window = new libxmljs.Window();

		console.log = 1234;
	},Error)
	
	assert.done();
}

module.exports.tearDown = function(callback) {
	console.log = consoleLog;
	callback();
}