const {describe, it} = require('mocha');
const assert = require('assert');
const c2spot = require('./../build/Release/c2spot.node');

// https://developer.ibm.com/tutorials/learn-nodejs-unit-testing-in-nodejs/

describe('simple test function', function() {
  it('1==1 should always be true', function() {
    assert(1==1);
  });
});

describe('Send basic request', function() {
  it('Sendin to google?', function() {
    assert(c2spot.sendRequest('https://google.com') == 0);
  });
});


