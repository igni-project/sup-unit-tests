# SUP (Scene Update Protocol) Unit Tests

When creating an application that handles SUP data, unit tests are a must. `sup-unit-tests` runs through the [Scene Update Protocol](https://github.com/igni-project/sup), one request at a time. This program generates a consistent set of collision queries for developers to test against their own software.

## Usage

To test a connection, enter the command `sup_unit_tests` followed by the domain address(es) of the socket you wish to test.

For example: `sup_unit_tests /run/user/$UID/sup1 /run/user/$UID/sup2`

