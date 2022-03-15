const {describe, it} = require('mocha');
const assert = require('assert');
const c2spot = require('./../build/Release/c2spot.node');

// https://developer.ibm.com/tutorials/learn-nodejs-unit-testing-in-nodejs/

describe('Send Auth', function() {
  it('Does authentication error?', function() {
    assert(c2spot.authRequest() == 0);
  });
});


