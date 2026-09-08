#!/bin/sh
git status --ignored --porcelain | grep '^!!' | cut -c4-
