var uname2 = require('../');
var assert = require('assert');


describe('uname2', function() {
  it('should export a function that returns a string', function() {
    assert.equal(typeof uname2.sysname(), 'string');
  });
  
  it('should export a function that returns a string', function() {
    assert.equal(typeof uname2.nodename(), 'string');
  });
  
  it('should export a function that returns a string', function() {
    assert.equal(typeof uname2.release(), 'string');
  });
  
  it('should export a function that returns a string', function() {
    assert.equal(typeof uname2.version(), 'string');
  });
  
  it('should export a function that returns a string', function() {
    assert.equal(typeof uname2.machine(), 'string');
  });

});
