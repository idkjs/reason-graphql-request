// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var GraphqlRequest = require("graphql-request");

var uri = "https://api.graph.cool/simple/v1/cj9o4se940gsu0148s5a4helr";

var query = "\n    query allCompanies($filter: String) {\n        companies: allCompanies(filter: \n        { name_contains: $filter\n        }) {\n          id\n          name\n        }\n      }";

var filtering2 = {
  filter: "tast"
};

var filtering = {
  filter: "tast"
};

console.log(filtering2);

console.log(filtering);

GraphqlRequest.request(uri, query, filtering2).then((function (data) {
        return Promise.resolve((console.log(data), /* () */0));
      }));

exports.uri        = uri;
exports.query      = query;
exports.filtering2 = filtering2;
exports.filtering  = filtering;
/*  Not a pure module */
