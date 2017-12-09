// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var GraphqlRequest = require("graphql-request");

var uri = "https://api.graph.cool/simple/v1/cj9o4se940gsu0148s5a4helr";

var query = (
    `query allCompanies($filter: String) {
        companies: allCompanies(filter: 
        { name_contains: $filter
        }) {
          id
          name
        }
      }`
);

GraphqlRequest.request(uri, query).then((function (data) {
        return Promise.resolve((console.log(data), /* () */0));
      }));

exports.uri   = uri;
exports.query = query;
/* query Not a pure module */
