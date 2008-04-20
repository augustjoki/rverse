@interface SpeedDialView
{
	UIView * _contentLayer; // @"UIView"
	UINavigationBar * _navBar; // @"UINavigationBar"
	UITable * _table; // @"UITable"
	ABPeoplePicker * _peoplePicker; // @"ABPeoplePicker"
	UITransitionView * _contentTransitionLayer; // @"UITransitionView"
	UIView * _cardViewer; // @"UIView"
	ABFavoritesEntry * _selectedABFavoritesEntry; // @"ABFavoritesEntry"
	UIView * _flyingView; // @"UIView"
	int _viewMode; // i
	int _selectedUID; // i
	bitfield _editable; // b1
}

- (void) cardViewer: (id) dismissActionsSheet: (id); // v16@0:4@8@12
- (void) cardViewer: (id) presentActionsSheet: (id); // v16@0:4@8@12
- (void) cardViewer: (id) selectedPerson: (void *) property: (int) identifier: (int); // v24@0:4@8^v12i16i20
- (void) unknownPersonCardViewer: (id) dismissPickingOverlay: (id); // v16@0:4@8@12
- (void) unknownPersonCardViewer: (id) presentPickingOverlay: (id); // v16@0:4@8@12
- (void) unknownPersonCardViewer: (id) didResolveToPerson: (void *); // v16@0:4@8^v12
- (void) navigationBar: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) navigationBar: (id) poppedItem: (id); // v16@0:4@8@12
- (void) table: (id) movedRow: (int) toRow: (int); // v20@0:4@8i12i16
- (int) selectedPersonUID; // i8@0:4
- (void) table: (id) disclosureClickedForRow: (int); // v16@0:4@8i12
- (void) table: (id) deleteRow: (int); // v16@0:4@8i12
- (void) tableSelectionDidChange: (id); // v12@0:4@8
- (char) table: (id) canDeleteRow: (int); // c16@0:4@8i12
- (char) table: (id) disclosureClickableForRow: (int); // c16@0:4@8i12
- (char) table: (id) showDisclosureForRow: (int); // c16@0:4@8i12
- (id) table: (id) cellForRow: (int) column: (id) reusing: (id); // @24@0:4@8i12@16@20
- (int) numberOfRowsInTable: (id); // i12@0:4@8
- (void) _addEntryAnimationCompleted: (id); // v12@0:4@8
- (char) peoplePicker: (id) shouldShowCardForPerson: (void *); // c16@0:4@8^v12
- (void) peoplePicker: (id) willDisplayMembersOfGroup: (void *); // v16@0:4@8^v12
- (void) peoplePicker: (id) selectedPerson: (void *) property: (int) identifier: (int); // v24@0:4@8^v12i16i20
- (void) _addEntryFromPeoplePickerForPerson: (void *) property: (int) identifier: (int) animateView: (id); // v24@0:4^v8i12i16@20
- (void) transitionViewDidComplete: (id); // v12@0:4@8
- (void) peoplePickerDidEndPicking: (id); // v12@0:4@8
- (void) _doneButtonClicked: (id); // v12@0:4@8
- (void) _editButtonClicked: (id); // v12@0:4@8
- (void) _addButtonClicked: (id); // v12@0:4@8
- (char) transition: (int) fromView: (id) toView: (id); // c20@0:4i8@12@16
- (void) showCardViewerForPerson: (void *) withTitle: (id) animate: (char); // v20@0:4^v8@12c16
- (void) _clearLastDialedDefaults; // v8@0:4
- (void) _entryChanged: (id); // v12@0:4@8
- (void) _favoritesListContentsDidChange: (id); // v12@0:4@8
- (void) updateNavBarButtonsForMode: (int); // v12@0:4i8
- (void) viewWillBeDisplayedAfterPhoneCall: (id); // v12@0:4@8
- (void) suspend: (int); // v12@0:4i8
- (void) restoreState; // v8@0:4
- (void) saveState; // v8@0:4
- (char) shouldSnapshot; // c8@0:4
- (void) showList: (char); // v12@0:4c8
- (void) setPrompt: (id); // v12@0:4@8
- (void) setEditable: (char); // v12@0:4c8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface SpeedDialCell
{
	UITextLabel * _labelTextLabel; // @"UITextLabel"
}

- (void) layoutSubviews; // v8@0:4
- (struct CGPoint) textInset; // {CGPoint=ff}8@0:4
- (void) removeControlWillHideRemoveConfirmation: (id); // v12@0:4@8
- (void) removeControlWillShowRemoveConfirmation: (id); // v12@0:4@8
- (void) _setLabelTextLabelHidden: (char); // v12@0:4c8
- (void) setDisplayName: (id); // v12@0:4@8
- (void) setLabel: (id); // v12@0:4@8
- (id) createRemoveControl; // @8@0:4
- (void) updateHighlightColors; // v8@0:4
- (id) _createLabelColor; // @8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (float) disclosureRightMargin; // f8@0:4
@end

@interface PhoneDock
{
	int _lastSelection; // i
}

- (void) _buttonClicked: (id); // v12@0:4@8
- (void) setBadge: (int) forViewType: (int); // v16@0:4i8i12
- (void) setVisibleButtons: (int); // v12@0:4i8
- (void) setSelectedViewType: (int); // v12@0:4i8
- (int) selectedViewType; // i8@0:4
- (id) initInView: (id) withFrame: (struct CGRect); // @28@0:4@8{CGRect={CGPoint=ff}{CGSize=ff}}12
@end

@interface PhoneViewController
{
	UIView * _view; // @"UIView"
	bitfield _editable; // b1
}

- (void) proximityStateChanged: (char); // v12@0:4c8
- (void) significantTimeChange; // v8@0:4
- (void) handleURL: (id); // v12@0:4@8
- (void) viewWillBeRedisplayed; // v8@0:4
- (void) viewWillBeDisplayedAfterPhoneCall: (id); // v12@0:4@8
- (void) viewWillBeDisplayed; // v8@0:4
- (void) prepareForSnapshot; // v8@0:4
- (void) suspend: (int); // v12@0:4i8
- (char) shouldSnapshot; // c8@0:4
- (int) selectedPersonUID; // i8@0:4
- (void) dealloc; // v8@0:4
- (char) showsDock; // c8@0:4
- (char) showsDesktop; // c8@0:4
- (char) isEditable; // c8@0:4
- (void) setEditable: (char); // v12@0:4c8
- (id) viewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface PhoneApplication
{
	UIWindow * _window; // @"UIWindow"
	UIView * _contentView; // @"UIView"
	UITransitionView * _transitionView; // @"UITransitionView"
	PhoneDock * _dock; // @"PhoneDock"
	PhoneDesktopView * _desktopView; // @"PhoneDesktopView"
	UIImage * _currentDesktopImage; // @"UIImage"
	PhoneCall * _currentDesktopCall; // @"PhoneCall"
	PhoneCall * _pendingDesktopCall; // @"PhoneCall"
	UIView * _slidingView; // @"UIView"
	int _currentViewType; // i
	int _preCallViewType; // i
	int _queuedViewType; // i
	PhoneViewController * _previousController; // @"PhoneViewController"
	PhoneViewController * _currentController; // @"PhoneViewController"
	UIModalView * _currentAlertSheet; // @"UIModalView"
	NSString * _prompt; // @"NSString"
	double _launchTime; // d
	 _badges; // [6i]
	int _badgeTotal; // i
	bitfield _badgePluses; // b6
	bitfield _isBootLaunch; // b1
	bitfield _urlCameWithActivation; // b1
	bitfield _urlIsInternal; // b1
	bitfield _inCallIsInBack; // b1
	bitfield _isEndingCall; // b1
	bitfield _isDialingCall; // b1
	bitfield _isAnimatingDial; // b1
	bitfield _isSwitchingView; // b1
	bitfield _suspendedInCall; // b1
	bitfield _isAnimating; // b1
	bitfield _isAnimatingToPreCallView; // b1
	bitfield _usesPrompt; // b1
	bitfield _inCallOverlayShowsDock; // b1
	bitfield _nextSuspensionIsForCallWaiting; // b1
	bitfield _desktopIsDefault; // b1
	bitfield _urlCameInstantFakeLocked; // b1
	bitfield _suspendingUnderLock; // b1
}

- (void) alertSheet: (id) buttonClicked: (int); // v16@0:4@8i12
- (char) dialVoicemail; // c8@0:4
- (char) dialPhoneNumber: (id); // c12@0:4@8
- (char) dialPhoneNumber: (id) dialAssist: (char); // c16@0:4@8c12
- (char) dialPhoneNumber: (id) forUID: (int) dialAssist: (char); // c20@0:4@8i12c16
- (char) shouldAttemptPhoneCall; // c8@0:4
- (void) _desktopFadedIn; // v8@0:4
- (void) _currentViewZoomedOut; // v8@0:4
- (void) _performDialOfNumber: (id) withCall: (id); // v16@0:4@8@12
- (void) _animateDialToInCallView; // v8@0:4
- (void) _animateOutgoingCallWithPreviousView: (id) startTime: (double); // v20@0:4@8d12
- (void) handleEvent: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
- (char) applicationIsReadyToSuspend; // c8@0:4
- (void) applicationDidResumeFromUnderLock; // v8@0:4
- (void) applicationWillSuspendUnderLock; // v8@0:4
- (void) beginLockSuspension; // v8@0:4
- (char) shouldHangUpOnLock; // c8@0:4
- (char) shouldAnimateLockIn; // c8@0:4
- (void) applicationOpenURL: (id); // v12@0:4@8
- (void) applicationOpenToShortCut: (id); // v12@0:4@8
- (char) openURL: (id); // c12@0:4@8
- (char) _shouldAnimateResumption; // c8@0:4
- (void) _updateApplicationBadge; // v8@0:4
- (int) badgeForView: (int); // i12@0:4i8
- (void) setBadge: (int) forView: (int); // v16@0:4i8i12
- (void) _setDockVisible: (char); // v12@0:4c8
- (char) dockIsInPlace; // c8@0:4
- (void) restoreDockToOwner; // v8@0:4
- (void) showDockViaView: (id); // v12@0:4@8
- (void) hideDockViaView: (id); // v12@0:4@8
- (void) _adjustViewToAccommodateDockInView: (id) pinningX: (char); // v16@0:4@8c12
- (void) dockSelectionReselected: (id); // v12@0:4@8
- (void) dockSelectionChanged: (id); // v12@0:4@8
- (id) _dock; // @8@0:4
- (void) setIgnoresInteractionEvents: (char); // v12@0:4c8
- (char) runTest: (id) options: (id); // c16@0:4@8@12
- (id) contentView; // @8@0:4
- (void) _setDesktopVisible: (char); // v12@0:4c8
- (void) _updateDesktopImageAfterInCallControllerSuspend: (id); // v12@0:4@8
- (void) _updateDesktopImage: (id); // v12@0:4@8
- (void) _reallyUpdateDesktopImageForCall: (id); // v12@0:4@8
- (id) _desktopImage; // @8@0:4
- (void) _phoneCallIdentityChanged: (id); // v12@0:4@8
- (void) _recacheDefaultDesktopImage; // v8@0:4
- (int) previouslySelectedPersonUID; // i8@0:4
- (char) dismissCurrentView; // c8@0:4
- (id) promptForController: (id); // @12@0:4@8
- (void) setInCallOverlayShowsDock: (char); // v12@0:4c8
- (void) setInCallPrompt: (id); // v12@0:4@8
- (void) _displayedCallsChanged: (id); // v12@0:4@8
- (void) _updateSuspendSettingsForViewType: (int); // v12@0:4i8
- (void) didReceiveMemoryWarning; // v8@0:4
- (void) _suspendPreviousController; // v8@0:4
- (void) transitionViewDidComplete: (id); // v12@0:4@8
- (id) currentViewController; // @8@0:4
- (void) _logSwitch; // v8@0:4
- (void) setCurrentView: (int) animating: (char); // v16@0:4i8c12
- (char) isDisplayingSheet; // c8@0:4
- (void) dismissAlertSheet; // v8@0:4
- (void) presentAlertSheet: (id); // v12@0:4@8
- (void) proximityStateChanged: (char); // v12@0:4c8
- (double) launchTime; // d8@0:4
- (void) userDefaultsDidChange: (id); // v12@0:4@8
- (void) significantTimeChange; // v8@0:4
- (void) dealloc; // v8@0:4
- (void) _initializeUI; // v8@0:4
- (void) _tearDownUI; // v8@0:4
- (void) applicationWillSuspendForEventsOnly; // v8@0:4
- (void) applicationDidResumeForEventsOnly; // v8@0:4
- (void) applicationResume: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
- (char) applicationSuspend: (struct __GSEvent *) settings: (id); // c16@0:4^{__GSEvent=}8@12
- (int) _didSuspendInCall: (class *); // i12@0:4^#8
- (void) _putSuspendSettingsInDictionary: (id) forControllerClass: (class); // v16@0:4@8#12
- (struct CGImage *) createApplicationDefaultPNG; // ^{CGImage=}8@0:4
- (id) nameOfDefaultImageToUpdateAtSuspension; // @8@0:4
- (char) _useLegacyEventSystem; // c8@0:4
- (void) applicationDidFinishLaunchingSuspended: (id); // v12@0:4@8
- (void) applicationDidFinishLaunching: (id); // v12@0:4@8
- (void) performCommonInitialization; // v8@0:4
@end

@interface SpeedDialController
{
	bitfield _listNeedsUpdate; // b1
	bitfield _suspended; // b1
}

- (void) _addressBookChanged; // v8@0:4
- (void) handleURL: (id); // v12@0:4@8
- (void) suspend: (int); // v12@0:4i8
- (char) shouldSnapshot; // c8@0:4
- (int) selectedPersonUID; // i8@0:4
- (void) setEditable: (char); // v12@0:4c8
- (void) dealloc; // v8@0:4
- (void) viewWillBeDisplayedAfterPhoneCall: (id); // v12@0:4@8
- (void) viewWillBeRedisplayed; // v8@0:4
- (void) viewWillBeDisplayed; // v8@0:4
- (id) viewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (id) init; // @8@0:4
@end

@interface AddressBookController
{
}

- (void) peoplePicker: (id) dismissAlertSheet: (id); // v16@0:4@8@12
- (void) peoplePicker: (id) presentAlertSheet: (id); // v16@0:4@8@12
- (void) peoplePickerDidEndPicking: (id); // v12@0:4@8
- (void) peoplePicker: (id) didTransitionFromFullScreenViewToView: (id); // v16@0:4@8@12
- (void) peoplePicker: (id) willTransitionFromFullScreenViewToView: (id); // v16@0:4@8@12
- (void) peoplePicker: (id) willTransitionToFullScreenViewFromView: (id); // v16@0:4@8@12
- (id) buttonBarForPeoplePicker: (id); // @12@0:4@8
- (void) peoplePicker: (id) selectedPerson: (void *) property: (int) identifier: (int); // v24@0:4@8^v12i16i20
- (void) viewWillBeDisplayedAfterPhoneCall: (id); // v12@0:4@8
- (void) suspend: (int); // v12@0:4i8
- (char) shouldSnapshot; // c8@0:4
- (void) setEditable: (char); // v12@0:4c8
- (void) viewWillBeRedisplayed; // v8@0:4
- (void) viewWillBeDisplayed; // v8@0:4
- (id) viewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) _updatePickerBanner: (id); // v12@0:4@8
- (void) _updatePickerPhoneNumber: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) init; // @8@0:4
@end

@interface RecentsController
{
	UIView * _navAndTransitionLayer; // @"UIView"
	UINavigationBar * _navBar; // @"UINavigationBar"
	UITransitionView * _transitionLayer; // @"UITransitionView"
	id<RecentsViewController> * _currentController; // @"<RecentsViewController>"
	UIView * _overlay; // @"UIView"
	int _viewedPersonUID; // i
	bitfield _suspended; // b1
}

- (void) alertSheet: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) _confirmClearRecents; // v8@0:4
- (void) significantTimeChange; // v8@0:4
- (void) transitionViewDidComplete: (id); // v12@0:4@8
- (void) dismissOverlay: (char); // v12@0:4c8
- (void) showOverlay: (id); // v12@0:4@8
- (void) navigationBar: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) navigationBar: (id) poppedItem: (id); // v16@0:4@8@12
- (void) showCallListAnimating: (char); // v12@0:4c8
- (void) showCallDetail: (id) animate: (char); // v16@0:4@8c12
- (void) _callDataChanged; // v8@0:4
- (void) showRecentsListUsingTransition: (int); // v12@0:4i8
- (void) setCurrentViewController: (id) usingTransition: (int) alwaysPush: (char); // v20@0:4@8i12c16
- (void) _showNavBarAccessoryView: (id); // v12@0:4@8
- (void) _hideNavBarAccessoryView: (id); // v12@0:4@8
- (void) _updateNavBarButtons; // v8@0:4
- (void) _updateLastViewedDate; // v8@0:4
- (struct CGRect) overlayRect; // {CGRect={CGPoint=ff}{CGSize=ff}}8@0:4
- (struct CGRect) contentRect; // {CGRect={CGPoint=ff}{CGSize=ff}}8@0:4
- (void) suspend: (int); // v12@0:4i8
- (char) shouldSnapshot; // c8@0:4
- (int) selectedPersonUID; // i8@0:4
- (void) viewWillBeDisplayedAfterPhoneCall: (id); // v12@0:4@8
- (void) viewWillBeRedisplayed; // v8@0:4
- (void) viewWillBeDisplayed; // v8@0:4
- (id) viewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (id) init; // @8@0:4
- (void) dealloc; // v8@0:4
- (void) tearDownUI; // v8@0:4
@end

@interface RecentCall
{
	int _type; // i
	NSString * _number; // @"NSString"
	NSDate * _date; // @"NSDate"
	NSString * _compositeName; // @"NSString"
	int _uid; // i
	int _identifier; // i
	bitfield _numberIsFormatted; // b1
	bitfield _numberIsBlocked; // b1
}

- (void) uncacheIdentity; // v8@0:4
- (void) setNumberIdentifier: (int); // v12@0:4i8
- (int) numberIdentifier; // i8@0:4
- (int) uid; // i8@0:4
- (void) setUid: (int); // v12@0:4i8
- (id) compositeName; // @8@0:4
- (id) dates; // @8@0:4
- (id) date; // @8@0:4
- (void) setDate: (id); // v12@0:4@8
- (char) numberIsBlocked; // c8@0:4
- (id) formattedNumber; // @8@0:4
- (id) number; // @8@0:4
- (void) setNumber: (id); // v12@0:4@8
- (int) type; // i8@0:4
- (void) setType: (int); // v12@0:4i8
- (char) canCoalesceWithCall: (id) givenCountryCode: (id); // c16@0:4@8@12
- (void) dealloc; // v8@0:4
- (id) initWithCTCall: (struct __CTCall *) givenCountryCode: (id); // @16@0:4^{__CTCall=}8@12
@end

@interface RecentMultiCall
{
	NSMutableArray * _dates; // @"NSMutableArray"
}

- (id) dates; // @8@0:4
- (id) occurrenceAtIndex: (int); // @12@0:4i8
- (int) numberOfOccurrences; // i8@0:4
- (void) addOccurrence: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
@end

@interface RecentsListController
{
	RecentsListLayer * _layer; // @"RecentsListLayer"
	int _filter; // i
}

- (void) _addressBookChanged; // v8@0:4
- (void) tearDown; // v8@0:4
- (struct __CFArray *) copyOrderedIndexesForFilter: (int); // ^{__CFArray=}12@0:4i8
- (int) tableFilter; // i8@0:4
- (void) setTableFilter: (int); // v12@0:4i8
- (void) table: (id) disclosureClickedForRow: (int); // v16@0:4@8i12
- (void) filteredTableAnimationFinished: (id); // v12@0:4@8
- (void) tableSelectionDidChange: (id); // v12@0:4@8
- (char) table: (id) disclosureClickableForRow: (int); // c16@0:4@8i12
- (char) table: (id) showDisclosureForRow: (int); // c16@0:4@8i12
- (id) table: (id) cellForRow: (int) column: (id); // @20@0:4@8i12@16
- (int) numberOfRowsInTable: (id); // i12@0:4@8
- (id) callForDate: (id); // @12@0:4@8
- (char) shouldSnapshot; // c8@0:4
- (id) rightNavigationButtonTitle; // @8@0:4
- (id) navigationAccessoryView; // @8@0:4
- (id) navigationTitle; // @8@0:4
- (void) loadCallData; // v8@0:4
- (void) displayScrollerIndicators; // v8@0:4
- (void) viewWillBeDisplayed; // v8@0:4
- (void) significantTimeChange; // v8@0:4
- (void) reloadCallData; // v8@0:4
- (id) layer; // @8@0:4
- (void) dealloc; // v8@0:4
- (id) init; // @8@0:4
@end

@interface RecentsListLayer
{
	FilteredTable * _table; // @"FilteredTable"
	ToggleButton * _toggleButton; // @"ToggleButton"
}

- (id) accessoryView; // @8@0:4
- (void) reloadData; // v8@0:4
- (void) segmentedControl: (id) selectedSegmentChanged: (int); // v16@0:4@8i12
- (void) setTableFilter: (int); // v12@0:4i8
- (void) setTableFilter: (int) animate: (char); // v16@0:4i8c12
- (void) clearSelection; // v8@0:4
- (void) displayScrollerIndicators; // v8@0:4
- (void) setScrollOffset: (float); // v12@0:4f8
- (float) scrollOffset; // f8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (void) setDataSource: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface RecentCallCell
{
	int _callType; // i
	NSString * _name; // @"NSString"
	NSString * _countString; // @"NSString"
	double _date; // d
}

- (id) _automationID; // @8@0:4
- (void) drawContentInRect: (struct CGRect) selected: (char); // v28@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8c24
- (void) setDate: (id); // v12@0:4@8
- (void) setCount: (int); // v12@0:4i8
- (void) setName: (id); // v12@0:4@8
- (void) setCallType: (int); // v12@0:4i8
- (float) disclosureRightMargin; // f8@0:4
- (void) dealloc; // v8@0:4
@end

@interface FilteredTable
{
	struct __CFArray * _orderedIndexes; // ^{__CFArray=}
	NSMutableArray * _postAnimationOrderedRows; // @"NSMutableArray"
	id _realDataSource; // @
	id _realDelegate; // @
	bitfield _animating; // b1
}

- (void) table: (id) disclosureClickedForRow: (int); // v16@0:4@8i12
- (void) tableRowSelected: (id); // v12@0:4@8
- (void) tableSelectionDidChange: (id); // v12@0:4@8
- (int) selectedRow; // i8@0:4
- (float) table: (id) heightForRow: (int); // f16@0:4@8i12
- (char) table: (id) disclosureClickableForRow: (int); // c16@0:4@8i12
- (char) table: (id) showDisclosureForRow: (int); // c16@0:4@8i12
- (id) table: (id) cellForRow: (int) column: (id); // @20@0:4@8i12@16
- (int) numberOfRowsInTable: (id); // i12@0:4@8
- (id) createPreparedCellForRow: (int) column: (int); // @16@0:4i8i12
- (void) setOffset: (struct CGPoint); // v16@0:4{CGPoint=ff}8
- (void) _finishAnimation; // v8@0:4
- (void) _finishAnimation: (id) finished: (id) context: (void *); // v20@0:4@8@12^v16
- (void) clearVisibleCellsWithoutRemovingFromSuperview; // v8@0:4
- (void) setFilteredIndexes: (struct __CFArray *) animate: (char); // v16@0:4^{__CFArray=}8c12
- (struct CGRect) rectOfRow: (int); // {CGRect={CGPoint=ff}{CGSize=ff}}12@0:4i8
- (id) viewAtColumn: (int) row: (int); // @16@0:4i8i12
- (id) _preparedRowCellForDataSourceRow: (int) layoutRow: (int) givenRowCount: (int); // @20@0:4i8i12i16
- (id) delegate; // @8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (void) setDataSource: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
@end

@interface RecentCallDetailController
{
	RecentCall * _call; // @"RecentCall"
	UIView * _layer; // @"UIView"
}

- (void) cardViewer: (id) dismissActionsSheet: (id); // v16@0:4@8@12
- (void) cardViewer: (id) presentActionsSheet: (id); // v16@0:4@8@12
- (void) cardViewer: (id) selectedPerson: (void *) property: (int) identifier: (int); // v24@0:4@8^v12i16i20
- (void) unknownPersonCardViewer: (id) didResolveToPerson: (void *); // v16@0:4@8^v12
- (void) unknownPersonCardViewer: (id) dismissPickingOverlay: (id); // v16@0:4@8@12
- (void) unknownPersonCardViewer: (id) presentPickingOverlay: (id); // v16@0:4@8@12
- (void) tearDown; // v8@0:4
- (id) layer; // @8@0:4
- (id) rightNavigationButtonTitle; // @8@0:4
- (id) navigationAccessoryView; // @8@0:4
- (id) navigationTitle; // @8@0:4
- (id) call; // @8@0:4
- (void) setCall: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
@end

@interface VoicemailController
{
}

- (void) _serviceRevoked: (id); // v12@0:4@8
- (void) significantTimeChange; // v8@0:4
- (void) proximityStateChanged: (char); // v12@0:4c8
- (void) suspend: (int); // v12@0:4i8
- (char) shouldSnapshot; // c8@0:4
- (int) selectedPersonUID; // i8@0:4
- (void) viewWillBeDisplayedAfterPhoneCall: (id); // v12@0:4@8
- (void) viewWillBeRedisplayed; // v8@0:4
- (void) viewWillBeDisplayed; // v8@0:4
- (id) viewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) dealloc; // v8@0:4
@end

@interface VoicemailView
{
	UIView * _contentLayer; // @"UIView"
	UINavigationBar * _navBar; // @"UINavigationBar"
	VoicemailControlsView * _controlsView; // @"VoicemailControlsView"
	VoicemailOfflineView * _offlineView; // @"VoicemailOfflineView"
	VoicemailMailboxController * _inboxController; // @"VoicemailMailboxController"
	VoicemailMailboxController * _trashController; // @"VoicemailMailboxController"
	VoicemailMailboxController * _currentController; // @"VoicemailMailboxController"
	UIView * _greetingView; // @"UIView"
	ABPeoplePicker * _peoplePicker; // @"ABPeoplePicker"
	UITransitionView * _contentTransitionLayer; // @"UITransitionView"
	UIView * _tableAndButtonBarLayer; // @"UIView"
	UIView * _cardViewer; // @"UIView"
	VoicemailSetupPlacard * _setupPlacard; // @"VoicemailSetupPlacard"
	VoicemailSetupController * _setupController; // @"VoicemailSetupController"
	VoicemailAudioRoutingController * _audioRoutingController; // @"VoicemailAudioRoutingController"
	VoicemailPlaybackController * _playbackController; // @"VoicemailPlaybackController"
	unsigned int _viewedPersonUID; // I
	bitfield _syncingTableSelection; // b1
	bitfield _startPlayingAfterFakeLoadData; // b1
	bitfield _isDismissingCardViewer; // b1
	bitfield _supressNavUnreadCount; // b1
	bitfield _suppressPasswordRequest; // b1
	bitfield _suspended; // b1
	bitfield _isShowingListProgress; // b1
	bitfield _showTrash; // b1
	bitfield _isRedisplaying; // b1
	bitfield _showHeaderProgress; // b1
}

- (void) cardViewer: (id) dismissActionsSheet: (id); // v16@0:4@8@12
- (void) cardViewer: (id) presentActionsSheet: (id); // v16@0:4@8@12
- (void) cardViewer: (id) selectedPerson: (void *) property: (int) identifier: (int); // v24@0:4@8^v12i16i20
- (void) unknownPersonCardViewer: (id) dismissPickingOverlay: (id); // v16@0:4@8@12
- (void) unknownPersonCardViewer: (id) presentPickingOverlay: (id); // v16@0:4@8@12
- (void) unknownPersonCardViewer: (id) didResolveToPerson: (void *); // v16@0:4@8^v12
- (void) voicemailGreetingEditViewDoneButtonClicked: (id); // v12@0:4@8
- (void) _getRidOfGreetingView; // v8@0:4
- (void) _restorePlaybackController; // v8@0:4
- (id) activeAudioRouteForAudioRoutingController: (id); // @12@0:4@8
- (char) speakerEnabledForAudioRoutingController: (id); // c12@0:4@8
- (void) audioRoutingController: (id) setSpeakerPhoneEnabled: (char); // v16@0:4@8c12
- (void) audioRoutingControllerDidFinishPicking: (id); // v12@0:4@8
- (void) audioRoutingControllerDevicesChanged: (id); // v12@0:4@8
- (void) navigationBar: (id) buttonClicked: (int); // v16@0:4@8i12
- (char) navigationBar: (id) shouldPopItem: (id); // c16@0:4@8@12
- (char) navigationBar: (id) shouldPushItem: (id); // c16@0:4@8@12
- (void) navigationBar: (id) poppedItem: (id); // v16@0:4@8@12
- (void) significantTimeChange; // v8@0:4
- (void) _voicemailTaskEnded: (id); // v12@0:4@8
- (void) _voicemailTaskStarted: (id); // v12@0:4@8
- (void) _updateProgressIndicator; // v8@0:4
- (void) _checkMailboxUsage; // v8@0:4
- (void) _mailboxSetupStateChanged; // v8@0:4
- (void) voicemailMailboxController: (id) entryDisclosureSelected: (void *) usingDisplayName: (id); // v20@0:4@8^v12@16
- (void) voicemailMailboxController: (id) entrySelected: (void *); // v16@0:4@8^v12
- (void) voicemailMailboxControllerExtraRowSelected: (id); // v12@0:4@8
- (void) _setupTrashControlButtonsWithDuration: (double); // v16@0:4d8
- (void) _setupInboxControlButtonsWithDuration: (double) forDefaultPNG: (char); // v20@0:4d8c16
- (void) _prepareControlsViewForTransition; // v8@0:4
- (void) alertSheet: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) voicemailControlsView: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) voicemailPlaybackController: (id) hadPlaybackError: (id); // v16@0:4@8@12
- (char) voicemailPlaybackControllerShouldEnableProximity: (id); // c12@0:4@8
- (void) voicemailPlaybackController: (id) speakerEnabledStateChanged: (char); // v16@0:4@8c12
- (void) voicemailPlaybackController: (id) playbackPathDidChange: (id); // v16@0:4@8@12
- (void) _updatePlaybackControlsForNullRecord; // v8@0:4
- (void) voicemailPlaybackController: (id) updateElapsedTime: (double) duration: (double) playableDuration: (double); // v36@0:4@8d12d20d28
- (void) voicemailSetupController: (id) didCompleteSuccessfully: (char); // v16@0:4@8c12
- (void) _checkForFailedSetup; // v8@0:4
- (void) voicemailSetupPlacardClicked: (id); // v12@0:4@8
- (void) voicemailOfflineViewCallButtonClicked: (id); // v12@0:4@8
- (void) _activationFailed: (id); // v12@0:4@8
- (void) _mwiStateChanged; // v8@0:4
- (void) _onlineStateChanged; // v8@0:4
- (void) _presentError: (id) blockingOthers: (char); // v16@0:4@8c12
- (void) _showCardViewerForRecord: (void *) displayName: (id) animate: (char); // v20@0:4^v8@12c16
- (void) _clearLastDialedDefaults; // v8@0:4
- (void) _updateProgressPref: (id); // v12@0:4@8
- (void) _trashedCountChanged: (id); // v12@0:4@8
- (void) _updateNavBarButtons; // v8@0:4
- (void) _updateNavTitle; // v8@0:4
- (char) shouldSnapshot; // c8@0:4
- (int) selectedPersonUID; // i8@0:4
- (void) transitionViewDidComplete: (id); // v12@0:4@8
- (char) suspended; // c8@0:4
- (void) proximityStateChanged: (char); // v12@0:4c8
- (void) _lazySync; // v8@0:4
- (void) suspend: (int); // v12@0:4i8
- (void) viewWillBeDisplayedAfterPhoneCall: (id); // v12@0:4@8
- (void) viewWillBeRedisplayed; // v8@0:4
- (void) viewWillBeDisplayed; // v8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailCell
{
	NSString * _displayName; // @"NSString"
	UIProgressIndicator * _progressIndicator; // @"UIProgressIndicator"
	double _date; // d
	bitfield _showUnreadMarker; // b1
	bitfield _playing; // b2
}

- (id) _automationID; // @8@0:4
- (void) drawContentInRect: (struct CGRect) selected: (char); // v28@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8c24
- (void) setSelected: (char) withFade: (char); // v16@0:4c8c12
- (void) setShowsProgressIndicator: (char); // v12@0:4c8
- (void) setPlaying: (char); // v12@0:4c8
- (void) _updatePlayingMarkers; // v8@0:4
- (void) _removePlaybackMarkers; // v8@0:4
- (void) setUnread: (char); // v12@0:4c8
- (void) setDate: (double); // v16@0:4d8
- (void) setDisplayName: (id); // v12@0:4@8
- (float) disclosureRightMargin; // f8@0:4
- (void) dealloc; // v8@0:4
@end

@interface VoicemailPlaybackController
{
	void * _currentVoicemailRecord; // ^v
	NSString * _currentPlaybackPath; // @"NSString"
	NSTimer * _progressUpdateTimer; // @"NSTimer"
	NSTimer * _seekTimer; // @"NSTimer"
	NSTimer * _delayedPlayTimer; // @"NSTimer"
	id _delegate; // @
	AVController * _avController; // @"AVController"
	int _lastSeekedToSecond; // i
	double _lastSeekedToDouble; // d
	float _preferredPlaybackRate; // f
	float _progressWidth; // f
	unsigned int _currentRecordExpectedLength; // I
	unsigned int _currentRecordLength; // I
	double _playableDuration; // d
	bitfield _finishedPlayback; // b1
	bitfield _ignoreElapsedTimeInUI; // b1
	bitfield _scrubbingWithProgressBar; // b1
	bitfield _displaying2xPlaybackRate; // b1
	bitfield _manuallyAdjustingPlaybackState; // b1
	bitfield _storeNeedsSave; // b1
	bitfield _speakerEnabled; // b1
	bitfield _finishedWhenScrubbed; // b1
	bitfield _pendingSeek; // b1
	bitfield _byeByeAV; // b1
}

- (void) _applicationDeactivated: (id); // v12@0:4@8
- (void) _applicationReactivated: (id); // v12@0:4@8
- (void) _enableVolumeChanges: (char); // v12@0:4c8
- (void) voicemailControllerDied: (id); // v12@0:4@8
- (void) voicemailPlaybackRateChangedNotification: (id); // v12@0:4@8
- (void) voicemailPlaybackStateDidStopNotification: (id); // v12@0:4@8
- (void) voicemailPlaybackStateDidChangeItemNotification: (id); // v12@0:4@8
- (void) _stopTimer; // v8@0:4
- (void) _startTimer; // v8@0:4
- (void) _updateProgress: (id); // v12@0:4@8
- (void) _timeJumped: (id); // v12@0:4@8
- (void) scrubberControl: (id) didChangeToScrubValue: (float); // v16@0:4@8f12
- (void) scrubberControl: (id) didEnterScrubbingState: (char); // v16@0:4@8c12
- (char) scrubberControlShouldBeginScrubbing: (id); // c12@0:4@8
- (void) seekingEnded; // v8@0:4
- (void) _stopSeekTimer; // v8@0:4
- (void) _updateSeekedValue; // v8@0:4
- (void) seekingStarted; // v8@0:4
- (void) _updateProgressUIProgress: (char); // v12@0:4c8
- (void) updateProximitySetting; // v8@0:4
- (void) routeChangedNotification: (id); // v12@0:4@8
- (char) speakerEnabled; // c8@0:4
- (void) setSpeakerEnabled: (char); // v12@0:4c8
- (id) activeAudioRoute; // @8@0:4
- (id) _speakerRouteSet; // @8@0:4
- (void) proximityStateChanged: (char); // v12@0:4c8
- (char) isPlayingWithDelay; // c8@0:4
- (char) isPlayingDoubleRate; // c8@0:4
- (char) isPlaying; // c8@0:4
- (void) toggleRate; // v8@0:4
- (void) togglePlayAllowingDelay: (char); // v12@0:4c8
- (void) _delayedTogglePlay: (id); // v12@0:4@8
- (void) stop; // v8@0:4
- (void) setCurrentVoicemailRecordDataLength: (unsigned int); // v12@0:4I8
- (id) playAllowingDelay: (char); // @12@0:4c8
- (id) playAllowingDelay: (char) expectedLength: (unsigned int) currentLength: (unsigned int); // @20@0:4c8I12I16
- (void) _clearDelayedPlayback; // v8@0:4
- (id) _delayedPlay: (id); // @12@0:4@8
- (void) setProgressWidth: (float); // v12@0:4f8
- (void) _updateAudioCategory; // v8@0:4
- (id) soundController; // @8@0:4
- (char) _hasVoicemailData; // c8@0:4
- (void *) currentVoicemailRecord; // ^v8@0:4
- (id) currentPlaybackPath; // @8@0:4
- (void) setCurrentPlaybackPath: (id); // v12@0:4@8
- (void) setCurrentVoicemailRecord: (void *); // v12@0:4^v8
- (void) _saveStoreIfNecessary; // v8@0:4
- (void) _addItemForCurrentVoicemailRecordIfNecessary; // v8@0:4
- (void) _updatePlayableDuration; // v8@0:4
- (void) suspend: (int); // v12@0:4i8
- (void) dealloc; // v8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (id) init; // @8@0:4
@end

@interface DialerCallButton
{
	struct CGSize _iconOffset; // {CGSize="width"f"height"f}
}

- (void) drawButtonPart: (int) inRect: (struct CGRect); // v28@0:4i8{CGRect={CGPoint=ff}{CGSize=ff}}12
- (char) titleIsTruncated; // c8@0:4
- (void) setIconOffset: (struct CGSize); // v16@0:4{CGSize=ff}8
@end

@interface DialerButton
{
	DialerController * _controller; // @"DialerController"
}

- (void) setDialerController: (id); // v12@0:4@8
@end

@interface DialerController
{
	UIView * _dialerView; // @"UIView"
	UIView<DialerNumberDisplay> * _lcd; // @"UIView<DialerNumberDisplay>"
	UINavigationBar * _navBar; // @"UINavigationBar"
	DialerPhonePad * _pad; // @"DialerPhonePad"
	DialerCallButton * _callButton; // @"DialerCallButton"
	DialerButton * _addContactButton; // @"DialerButton"
	DialerButton * _deleteButton; // @"DialerButton"
	UIView * _newContactView; // @"UIView"
	NSTimer * _deleteTimer; // @"NSTimer"
	NSTimer * _lookupTimer; // @"NSTimer"
	NSString * _myPrefix; // @"NSString"
	int _personUID; // i
	bitfield _numberChanged; // b1
	bitfield _calledNumber; // b1
	bitfield _inCallMode; // b1
	bitfield _didDeleteRepeat; // b1
}

- (id) navigationBarDefaultPrompt: (id); // @12@0:4@8
- (void) navigationBar: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) _deleteButtonDown: (id); // v12@0:4@8
- (void) _deleteButtonClicked: (id); // v12@0:4@8
- (void) _stopDeleteTimer; // v8@0:4
- (void) _startDeleteTimer; // v8@0:4
- (void) _deleteRepeat; // v8@0:4
- (void) peoplePicker: (id) editedPerson: (void *) property: (int) identifier: (int); // v24@0:4@8^v12i16i20
- (void) peoplePickerDidEndPicking: (id); // v12@0:4@8
- (void) newContactViewCompleted: (id) withNewPerson: (void *); // v16@0:4@8^v12
- (void) newContactViewCancelled: (id); // v12@0:4@8
- (void) alertSheet: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) transitionViewDidComplete: (id); // v12@0:4@8
- (void) _dismissNewContactView: (char); // v12@0:4c8
- (void) didDismissAlertSheet: (id); // v12@0:4@8
- (void) _addButtonClicked: (id); // v12@0:4@8
- (void) _addToNewContact; // v8@0:4
- (void) _cancelVoicemailDial; // v8@0:4
- (void) _dialVoicemail; // v8@0:4
- (void) phonePad: (id) keyUp: (char); // v16@0:4@8c12
- (void) phonePad: (id) keyDown: (char); // v16@0:4@8c12
- (id) _myPrefix; // @8@0:4
- (void) phonePadDeleteLastDigit: (id); // v12@0:4@8
- (void) phonePad: (id) appendString: (id); // v16@0:4@8@12
- (void) _callButtonPressed: (id); // v12@0:4@8
- (void) _updateCallButtonEnabledState: (id) updateNameNow: (char); // v16@0:4@8c12
- (int) selectedPersonUID; // i8@0:4
- (void) _updateName; // v8@0:4
- (void) _stopLookupTimer; // v8@0:4
- (char) shouldSnapshot; // c8@0:4
- (void) prepareForSnapshot; // v8@0:4
- (void) suspend: (int); // v12@0:4i8
- (void) _saveAndClear; // v8@0:4
- (void) dealloc; // v8@0:4
- (void) viewWillBeDisplayed; // v8@0:4
- (id) viewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (char) _callButtonTitleWillFit; // c8@0:4
- (id) imageForButton: (id *) forState: (int); // @16@0:4^@8i12
@end

@interface DialerNameView
{
	NSString * _name; // @"NSString"
	NSString * _label; // @"NSString"
}

- (void) drawRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) setLabel: (id); // v12@0:4@8
- (id) name; // @8@0:4
- (void) setName: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface DialerFieldView
{
	NSString * _text; // @"NSString"
}

- (void) drawRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (id) text; // @8@0:4
- (void) setText: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface DialerLCDField
{
	DialerFieldView * _field; // @"DialerFieldView"
	DialerNameView * _nameView; // @"DialerNameView"
}

- (void) setLabel: (id); // v12@0:4@8
- (id) name; // @8@0:4
- (void) setName: (id); // v12@0:4@8
- (void) setText: (id) needsFormat: (char); // v16@0:4@8c12
- (id) text; // @8@0:4
- (void) dealloc; // v8@0:4
- (void) delete; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface InCallBottomButton
{
}

- (char) pointMostlyInside: (struct CGPoint) forEvent: (struct __GSEvent *); // c20@0:4{CGPoint=ff}8^{__GSEvent=}16
@end

@interface InCallController
{
	UIView * _inCallView; // @"UIView"
	InCallLCDView * _lcd; // @"InCallLCDView"
	TPBottomButtonBar * _bottomBar; // @"TPBottomButtonBar"
	TPBottomDualButtonBar * _emergencyCallBottomBar; // @"TPBottomDualButtonBar"
	TPBottomDualButtonBar * _ttyBottomBar; // @"TPBottomDualButtonBar"
	TPBottomDualButtonBar * _dualBottomBar; // @"TPBottomDualButtonBar"
	TPBottomButtonBar * _defaultBottomBar; // @"TPBottomButtonBar"
	SixSquareView * _sixSquare; // @"SixSquareView"
	TPPhonePad * _phonePad; // @"TPPhonePad"
	UIView * _centerView; // @"UIView"
	UIView * _conferenceView; // @"UIView"
	UITable * _conferenceTable; // @"UITable"
	InCallLCDField * _field; // @"InCallLCDField"
	NSTimer * _emergencyCallCycleTimer; // @"NSTimer"
	int _emergencyCallCycleIndex; // i
	NSArray * _emergencyCallStrings; // @"NSArray"
	TPBottomLockBar * _fakeLockBar; // @"TPBottomLockBar"
	AudioDeviceView * _routeList; // @"AudioDeviceView"
	NSTimer * _autodismissRouteListTimer; // @"NSTimer"
	AudioDeviceController * _deviceController; // @"AudioDeviceController"
	SEL _passcodeUnlockAction; // :
	 _calls; // [2@"PhoneCall"]
	NSTimer * _durationTimer; // @"NSTimer"
	NSArray * _displayedConferenceMembers; // @"NSArray"
	int _lastConferenceParticipantCount; // i
	bitfield _pendingDisconnect; // b2
	bitfield _currentCallCount; // b2
	bitfield _currentCall; // b2
	bitfield _currentCallProvisional; // b1
	bitfield _conference; // b2
	bitfield _dontSuspend; // b1
	bitfield _suspended; // b1
	bitfield _tonePlayed; // b1
	bitfield _disconnecting; // b1
	bitfield _disconnectingConference; // b1
	bitfield _disconnectingAnimationStarted; // b1
	bitfield _timerDisabled; // b1
	bitfield _animatingConferenceCell; // b1
	bitfield _performingAnimation; // b1
	bitfield _queuedControlFailure; // b1
	bitfield _nextUpdateIsReset; // b1
	bitfield _checkKeypadOnNextUpdate; // b1
	bitfield _isMergingCalls; // b1
	bitfield _isGoingPrivate; // b1
	bitfield _routesEnabled; // b1
	bitfield _suspendingUnderLock; // b1
	bitfield _returnToLastViewAfterLock; // b1
	bitfield _blinkCount; // b3
	bitfield _handlingEmergencyCall; // b1
	bitfield _preToneMuteState; // b2
}

- (double) _alternatingDurationForCall: (id); // d12@0:4@8
- (id) _alternateDisplayNameForCall: (id); // @12@0:4@8
- (void) _setDefaultBottomBarButtonAlpha: (float) forDualBarSwitch: (char); // v16@0:4f8c12
- (void) _restoreAnimatingButtonsFromView: (id); // v12@0:4@8
- (id) _createEndCallButtonWithTitle: (id) small: (char) allowPressAndHold: (char); // @20@0:4@8c12c16
- (void) _setSpeakerPhoneEnabled: (char); // v12@0:4c8
- (void) inCallLCDViewPopTextCompleted: (id); // v12@0:4@8
- (void) _mergeAnimationCompleted; // v8@0:4
- (void) animateCallMerge; // v8@0:4
- (void) _finishedAnimatingInternalDial; // v8@0:4
- (void) animateForDialWithStartTime: (double); // v16@0:4d8
- (void) cancelCallWaitingAlert; // v8@0:4
- (void) _finishedCallWaitingFlip; // v8@0:4
- (void) animateOutOfCallWaitingAlert; // v8@0:4
- (char) animateToCallWaitingAlertForCall: (id) name: (id) label: (id) uid: (int); // c24@0:4@8@12@16i20
- (void) flipToCallWaiting: (char) fromTTY: (char) withName: (id) label: (id) uid: (int) phoneCall: (id); // v32@0:4c8c12@16@20i24@28
- (void) _answerAnimationFinished; // v8@0:4
- (void) _incomingButtonsFaded; // v8@0:4
- (void) handleURL: (id); // v12@0:4@8
- (void) _setResumeToKeypad: (char); // v12@0:4c8
- (void) _reset; // v8@0:4
- (void) _singleCallDisconnectAnimationFinished; // v8@0:4
- (void) setDisplayedCalls: (id); // v12@0:4@8
- (void) _setCallCount: (int); // v12@0:4i8
- (void) _setCallIndex: (unsigned int) toCall: (id); // v16@0:4I8@12
- (void) didFinishAnimatingUnderLockSuspension; // v8@0:4
- (char) _lockCompleteState; // c8@0:4
- (void) _lockCompletedWhileOnCall; // v8@0:4
- (void) _lockCompleted; // v8@0:4
- (void) animateResumeFromUnderLock: (char); // v12@0:4c8
- (void) didFinishAnimatingResumeFromUnderLock; // v8@0:4
- (void) animateUnderLockSuspension: (char) blinkEndCallButton: (char) afterDelay: (float); // v20@0:4c8c12f16
- (void) _blinkEndCallButton; // v8@0:4
- (void) _finishedBlinking; // v8@0:4
- (void) _animateUnderLockSuspension: (char); // v12@0:4c8
- (id) currentBottomBar; // @8@0:4
- (char) isSuspendingUnderLock; // c8@0:4
- (char) isShowingLock; // c8@0:4
- (void) animateEndOfCall; // v8@0:4
- (void) _conferenceParticipantsChanged: (id); // v12@0:4@8
- (void) _displayedCallsChanged: (id); // v12@0:4@8
- (void) _callDisplayNameChangedNotification: (id); // v12@0:4@8
- (void) _callStatusChangedNotification: (id); // v12@0:4@8
- (void) _callStatusChanged: (id); // v12@0:4@8
- (void) _updateDuration; // v8@0:4
- (void) _updateStatus: (unsigned int) provisionally: (char); // v16@0:4I8c12
- (void) _setDisableTimerUpdates: (char); // v12@0:4c8
- (void) _setConferenceCall: (unsigned int); // v12@0:4I8
- (void) _updateSingleCallerPhoto; // v8@0:4
- (id) _updateConferenceDisplayNameCache; // @8@0:4
- (void) _setCurrentCall: (unsigned int); // v12@0:4I8
- (void) _updateCurrentCallDisplay; // v8@0:4
- (void) _unprovisionalize; // v8@0:4
- (void) _updateConferenceButtonStateGivenCurrentCallState: (int); // v12@0:4i8
- (void) _applicationDeactivated: (id); // v12@0:4@8
- (void) _applicationReactivated: (id); // v12@0:4@8
- (void) _finishedAnimatingToLastView; // v8@0:4
- (void) _handleEndOfLastCall; // v8@0:4
- (void) _postOkToDim; // v8@0:4
- (char) _lockWasInterrupted; // c8@0:4
- (void) _startEndOfLastCallAnimationRelocking; // v8@0:4
- (void) _startEndOfLastCallAnimation; // v8@0:4
- (void) _startEndOfLastCallAnimationWithRelock: (char); // v12@0:4c8
- (void) cancelAnimateToPreviousView; // v8@0:4
- (void) _animateToLastView: (char); // v12@0:4c8
- (void) _finishedAnimatingToPreviousApp; // v8@0:4
- (void) animateToPreviousAppWithStartTime: (double); // v16@0:4d8
- (void) _animateCommonEndOfCallWithStartTime: (double) duration: (float) delay: (float) didEndSelector: (SEL); // v28@0:4d8f16f20:24
- (void) _endCallSingleBarFadedIn; // v8@0:4
- (void) _endCallDualBarFadedOut; // v8@0:4
- (void) _cancelEndAllCalls: (id); // v12@0:4@8
- (void) _endCallDualBarFadedIn; // v8@0:4
- (void) _endCallSingleBarFadedOut; // v8@0:4
- (void) _endCallLongPress: (id); // v12@0:4@8
- (void) _endCallExited: (id); // v12@0:4@8
- (void) _endCallDown: (id); // v12@0:4@8
- (void) _endCallClicked: (id); // v12@0:4@8
- (void) _performDisconnectOfCurrentCall; // v8@0:4
- (void) _updatePendingDisconnectState; // v8@0:4
- (void) _setEndCallButtonDimmed: (char); // v12@0:4c8
- (void) sixSquareButtonHeldDown: (int); // v12@0:4i8
- (void) _setSpeakerPositionAsRoute: (char); // v12@0:4c8
- (void) sixSquareButtonClicked: (int); // v12@0:4i8
- (void) _showAddCall; // v8@0:4
- (void) _showContacts; // v8@0:4
- (void) _showPasscodeKeypadForOperation: (SEL); // v12@0:4:8
- (void) inCallLCDViewConferenceButtonClicked: (id); // v12@0:4@8
- (void) inCallLCDViewCompletedAnimation: (id); // v12@0:4@8
- (void) inCallLCDView: (id) positionTapped: (int); // v16@0:4@8i12
- (void) _keypadFieldFadedOut; // v8@0:4
- (void) inCallLCDFieldSendButtonClicked: (id); // v12@0:4@8
- (char) _sendEnteredDigitsAndForceActive: (char); // c12@0:4c8
- (void) _keypadDualBottomBarFadedOut; // v8@0:4
- (void) _hideKeypadClicked: (id); // v12@0:4@8
- (void) _restorePreToneMuteState; // v8@0:4
- (void) phonePadDidEndSounds: (id); // v12@0:4@8
- (void) phonePadWillBeginSounds: (id); // v12@0:4@8
- (void) phonePad: (id) replaceLastDigitWithString: (id); // v16@0:4@8@12
- (void) phonePad: (id) keyUp: (char); // v16@0:4@8c12
- (void) phonePad: (id) keyDown: (char); // v16@0:4@8c12
- (void) _keypadFieldFadedIn; // v8@0:4
- (void) _keypadSingleBottomBarFadedOut; // v8@0:4
- (void) _keypadDualBottomBarFadedIn; // v8@0:4
- (void) inCallLCDFieldDeleteButtonClicked: (id); // v12@0:4@8
- (void) _cancelEmergencyCall: (id); // v12@0:4@8
- (void) _placeEmergencyCall: (id); // v12@0:4@8
- (void) _showEmergencyCallUI; // v8@0:4
- (void) _cycleEmergencyLabel; // v8@0:4
- (void) _stopCyclingEmergencyLabel; // v8@0:4
- (void) _clearEmergencyCallUI; // v8@0:4
- (void) _showKeypadDualBottomBar; // v8@0:4
- (void) _revealKeypadWithDuration: (float) label: (id); // v16@0:4f8@12
- (void) _dualDismissButtonClicked: (id); // v12@0:4@8
- (void) _setupDualBottomBarWithEndTitle: (id) dismissTitle: (id); // v16@0:4@8@12
- (void) _toggleHold; // v8@0:4
- (void) _muteChanged: (id); // v12@0:4@8
- (void) swapCalls; // v8@0:4
- (char) showsDock; // c8@0:4
- (char) showsDesktop; // c8@0:4
- (void) suspend: (int); // v12@0:4i8
- (char) shouldSnapshot; // c8@0:4
- (void) viewWillBeDisplayed; // v8@0:4
- (void) dealloc; // v8@0:4
- (id) viewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface InCallLCDView
{
	TPLCDTextView * _labelView2; // @"TPLCDTextView"
	TPLCDTextView * _textView2; // @"TPLCDTextView"
	UIView * _activeIndicator; // @"UIView"
	int _activePosition; // i
	int _conferencePosition; // i
	UIImageView * _oldBkgndView; // @"UIImageView"
	UIImageView * _newBkgndView; // @"UIImageView"
	TPLCDTextView * _oldLabelView; // @"TPLCDTextView"
	TPLCDTextView * _oldLabelView2; // @"TPLCDTextView"
	TPLCDTextView * _oldTextView; // @"TPLCDTextView"
	TPLCDTextView * _oldTextView2; // @"TPLCDTextView"
	UIView * _oldActiveIndicator; // @"UIView"
	UIPushButton * _conferenceButton; // @"UIPushButton"
	NSTimer * _alternatingTimer; // @"NSTimer"
	double _alternatingDuration; // d
	double _alternatingDuration2; // d
	NSString * _originalText; // @"NSString"
	NSString * _originalText2; // @"NSString"
	NSString * _alternateText; // @"NSString"
	NSString * _alternateText2; // @"NSString"
	id _delegate; // @
	bitfield _ignoreLayout; // b1
	bitfield _animating; // b1
	bitfield _progress; // b1
	bitfield _dimmedText; // b2
	bitfield _canTruncateLabel; // b2
	bitfield _enableFade; // b1
	bitfield _changingForAlternate; // b1
}

- (void) _alternate: (id); // v12@0:4@8
- (void) _stopAlternating: (char); // v12@0:4c8
- (void) _startAlternating; // v8@0:4
- (void) _finishedAnimatingLabel; // v8@0:4
- (void) animateLabel; // v8@0:4
- (void) _popTextFinished; // v8@0:4
- (void) _popTextFinishedFirstHalf; // v8@0:4
- (void) popText; // v8@0:4
- (void) animateCallMergeWithDuration: (float); // v12@0:4f8
- (int) conferencePosition; // i8@0:4
- (void) setConferencePosition: (int); // v12@0:4i8
- (void) _conferenceButtonClicked: (id); // v12@0:4@8
- (void) _positionConferenceButton; // v8@0:4
- (void) mouseUp: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
- (void) setActiveIndicatorShowsProgress: (char); // v12@0:4c8
- (void) _activationAnimationFinished; // v8@0:4
- (void) animateToActivePosition: (int) label: (id) label2: (id); // v20@0:4i8@12@16
- (void) setActivePosition: (int); // v12@0:4i8
- (void) _updateForActivePosition; // v8@0:4
- (id) _backgroundForPosition: (int); // @12@0:4i8
- (void) _removeAnimationViews; // v8@0:4
- (void) _positionActiveCallIndicator; // v8@0:4
- (void) setSubImage: (id); // v12@0:4@8
- (void) setAlternateText2: (id) forDuration: (double); // v20@0:4@8d12
- (void) setAlternateText: (id) forDuration: (double); // v20@0:4@8d12
- (void) setCanTruncateLabel2: (char); // v12@0:4c8
- (id) label2; // @8@0:4
- (void) setLabel2: (id); // v12@0:4@8
- (id) text2; // @8@0:4
- (void) setText2: (id) animating: (char); // v16@0:4@8c12
- (void) setText2Dimmed: (char); // v12@0:4c8
- (void) setText2: (id); // v12@0:4@8
- (void) setCanTruncateLabel: (char); // v12@0:4c8
- (void) setLabelVisible: (char); // v12@0:4c8
- (void) setLabel: (id); // v12@0:4@8
- (void) setTextDimmed: (char); // v12@0:4c8
- (void) setText: (id) animating: (char); // v16@0:4@8c12
- (void) setText: (id); // v12@0:4@8
- (void) setTextChangeFadingEnabled: (char); // v12@0:4c8
- (void) setTextScrolls: (char); // v12@0:4c8
- (void) lcdTextViewCompletedScroll: (id); // v12@0:4@8
- (void) performTextFadeWithDuration: (float) delay: (float) forView: (id) newText: (id); // v24@0:4f8f12@16@20
- (void) _enableScrollingForTextView: (id) start: (char); // v16@0:4@8c12
- (void) _cancelScrollingForTextView: (id); // v12@0:4@8
- (void) _updateTextAttributes; // v8@0:4
- (void) removeFromSuperview; // v8@0:4
- (void) layoutSubviews; // v8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
@end

@interface ToggleButton
{
}

- (char) pointInside: (struct CGPoint) forEvent: (struct __GSEvent *); // c20@0:4{CGPoint=ff}8^{__GSEvent=}16
- (id) initWithWidth: (float) leftTitle: (id) rightTitle: (id); // @20@0:4f8@12@16
@end

@interface RecentsButtonBar
{
}

- (id) createButtonWithDescription: (id); // @12@0:4@8
@end

@interface SixSquareButton
{
	char _selected; // c
	UIImage * _bkgnd; // @"UIImage"
	UIImage * _selectedBkgnd; // @"UIImage"
	struct CGRect _contentRect; // {CGRect="origin"{CGPoint="x"f"y"f}"size"{CGSize="width"f"height"f}}
	bitfield _isDisabled; // b1
}

- (void) _sizeToFit; // v8@0:4
- (void) drawButtonPart: (int) inRect: (struct CGRect); // v28@0:4i8{CGRect={CGPoint=ff}{CGSize=ff}}12
- (void) drawContents; // v8@0:4
- (void) drawBackground; // v8@0:4
- (void) setContentRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) setSelectedBackgroundImage: (id); // v12@0:4@8
- (void) setBackgroundImage: (id); // v12@0:4@8
- (char) isReallyEnabled; // c8@0:4
- (void) setEnabled: (char); // v12@0:4c8
- (char) selected; // c8@0:4
- (void) setSelected: (char); // v12@0:4c8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface SixSquareView
{
	 _buttons; // [6@"SixSquareButton"]
	id _delegate; // @
}

- (void) setAllButtonsEnabled: (char); // v12@0:4c8
- (id) buttonAtPosition: (int); // @12@0:4i8
- (void) _cancelButtonDown: (id); // v12@0:4@8
- (void) _buttonDown: (id); // v12@0:4@8
- (void) _buttonHeldDown: (id); // v12@0:4@8
- (void) _buttonClicked: (id); // v12@0:4@8
- (void) setTitle: (id) image: (id) forPosition: (int); // v20@0:4@8@12i16
- (void) setDelegate: (id); // v12@0:4@8
- (void) removeFromSuperview; // v8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface DialerPhonePad
{
}

- (float) _yFudge; // f8@0:4
- (id) _keypadImage; // @8@0:4
- (void) willBecomeVisible; // v8@0:4
- (void) hiddenFromView; // v8@0:4
- (id) _pressedImage; // @8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface ConferenceManagementTable
{
	bitfield _displaysPrivate; // b1
	UIView * _eventTarget; // @"UIView"
}

- (void) completeRowDeletionAnimation; // v8@0:4
- (void) animateDeletionOfRowWithCell: (id) viaEdge: (int); // v16@0:4@8i12
- (void) conferenceParticipantCellEndClicked: (id); // v12@0:4@8
- (void) conferenceParticipantCellPrivateClicked: (id); // v12@0:4@8
- (int) rowForCell: (id); // i12@0:4@8
- (id) hitTest: (struct CGPoint) forEvent: (struct __GSEvent *); // @20@0:4{CGPoint=ff}8^{__GSEvent=}16
- (void) sendEventsToView: (id); // v12@0:4@8
- (void) setDisplaysPrivateButtons: (char); // v12@0:4c8
- (id) createPreparedCellForRow: (int) column: (int); // @16@0:4i8i12
- (void) selectRow: (int) byExtendingSelection: (char) withFade: (char); // v20@0:4i8c12c16
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface EndCallExtrudeAnimation
{
	float _startTitleAlpha; // f
	float _endTitleAlpha; // f
}

- (void) setProgress: (float); // v12@0:4f8
- (void) setEndTitleAlpha: (float); // v12@0:4f8
- (void) setStartTitleAlpha: (float); // v12@0:4f8
@end

@interface ConferencePillButton
{
	float _titleAlpha; // f
	struct CGRect _titleBounds; // {CGRect="origin"{CGPoint="x"f"y"f}"size"{CGSize="width"f"height"f}}
}

- (char) _alwaysHandleScrollerMouseEvent; // c8@0:4
- (float) minTitleMargin; // f8@0:4
- (void) drawTitleAtPoint: (struct CGPoint) width: (float); // v20@0:4{CGPoint=ff}8f16
- (void) drawButtonPart: (int) inRect: (struct CGRect); // v28@0:4i8{CGRect={CGPoint=ff}{CGSize=ff}}12
- (struct CGSize) sizeForTitle; // {CGSize=ff}8@0:4
- (void) setFrame: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) setTitleAlpha: (float); // v12@0:4f8
- (id) initWithFrame: (struct CGRect) backgroundImage: (id) pressedBackgroundImage: (id) slices: (struct ?); // @80@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8@24@28{?={CGRect={CGPoint=ff}{CGSize=ff}}{CGRect={CGPoint=ff}{CGSize=ff}}{CGRect={CGPoint=ff}{CGSize=ff}}}32
@end

@interface ConferenceEndCallButton
{
}

- (char) _alwaysHandleScrollerMouseEvent; // c8@0:4
- (void) drawButtonPart: (int) inRect: (struct CGRect); // v28@0:4i8{CGRect={CGPoint=ff}{CGSize=ff}}12
- (id) initWithDefaultSize; // @8@0:4
@end

@interface ConferenceParticipantHoldView
{
}

@end

@interface ConferenceParticipantNameView
{
	NSString * _name; // @"NSString"
	float _desiredWidth; // f
}

- (void) drawRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (float) desiredWidth; // f8@0:4
- (void) setFrame: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) dealloc; // v8@0:4
- (id) initWithName: (id); // @12@0:4@8
@end

@interface ConferenceParticipantCell
{
	ConferenceManagementTable * _table; // @"ConferenceManagementTable"
	UIPushButton * _privateButton; // @"UIPushButton"
	UIPushButton * _endButton; // @"UIPushButton"
	UIThreePartButton * _bigEndButton; // @"UIThreePartButton"
	ConferenceParticipantNameView * _nameView; // @"ConferenceParticipantNameView"
	bitfield _isConfirming; // b1
	bitfield _isHeld; // b1
	bitfield _drawSeparator; // b1
}

- (void) mouseUp: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
- (id) hitTest: (struct CGPoint) forEvent: (struct __GSEvent *); // @20@0:4{CGPoint=ff}8^{__GSEvent=}16
- (void) _privateButtonClicked: (id); // v12@0:4@8
- (void) _endCallConfirmAnimationFinished; // v8@0:4
- (void) _endButtonClicked: (id); // v12@0:4@8
- (void) _setShowConfirm: (char); // v12@0:4c8
- (void) _privateButtonFadedOut; // v8@0:4
- (void) setShowPrivateButton: (char); // v12@0:4c8
- (void) makeHeld; // v8@0:4
- (void) setTable: (id); // v12@0:4@8
- (void) drawRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) setShouldDrawSeparator: (char); // v12@0:4c8
- (void) setBackgroundColor: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect) name: (id); // @28@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8@24
@end

@interface InCallLCDField
{
	UIThreePartButton * _button; // @"UIThreePartButton"
	id _delegate; // @
	bitfield _textIsPlaceholder; // b1
}

- (struct CGRect) textFrame; // {CGRect={CGPoint=ff}{CGSize=ff}}8@0:4
- (id) text; // @8@0:4
- (void) setText: (id); // v12@0:4@8
- (void) setPlaceholderText: (id) animating: (char); // v16@0:4@8c12
- (void) setShowsDeleteButton: (char); // v12@0:4c8
- (void) _deleteButtonClicked: (id); // v12@0:4@8
- (void) _sendButtonClicked: (id); // v12@0:4@8
- (char) showsSendButton; // c8@0:4
- (void) setShowsSendButton: (char); // v12@0:4c8
- (void) _showButtonWithTitle: (id) action: (SEL); // v16@0:4@8:12
- (void) _removeButton; // v8@0:4
- (void) _updateButton; // v8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
@end

@interface DialerNavigationBar
{
	NSString * _label; // @"NSString"
	bitfield _isDisplayingPlaceholder; // b1
}

- (void) _drawPrompt: (id) inRect: (struct CGRect) withFont: (id) barStyle: (int); // v36@0:4@8{CGRect={CGPoint=ff}{CGSize=ff}}12@28i32
- (void) delete; // v8@0:4
- (void) setLabel: (id); // v12@0:4@8
- (id) name; // @8@0:4
- (void) setName: (id); // v12@0:4@8
- (void) setText: (id) needsFormat: (char); // v16@0:4@8c12
- (id) text; // @8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailPushButton
{
	int _originalColor; // i
}

- (void) setEnabled: (char); // v12@0:4c8
- (id) initWithTitle: (id) icon: (id) color: (int) frame: (struct CGRect); // @36@0:4@8@12i16{CGRect={CGPoint=ff}{CGSize=ff}}20
@end

@interface VoicemailControlsView
{
	UIScrubberControl * _progressControl; // @"UIScrubberControl"
	VoicemailPushButton * _leftButton; // @"VoicemailPushButton"
	VoicemailPushButton * _rightButton; // @"VoicemailPushButton"
	float _fontSize; // f
	id _delegate; // @
}

- (void) drawRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) _buttonTransitionComplete; // v8@0:4
- (void) _animateNewButtonsIn: (id) finished: (id) duration: (id); // v20@0:4@8@12@16
- (void) setLeftButtonColor: (int) title: (id) icon: (id) rightButtonColor: (int) title: (id) icon: (id) duration: (double); // v40@0:4i8@12@16i20@24@28d32
- (void) setButtonFontSize: (float); // v12@0:4f8
- (void) setButtons: (int) enabled: (char); // v16@0:4i8c12
- (void) _bottomButtonClicked: (id); // v12@0:4@8
- (id) progressControl; // @8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect) showProgressTimes: (char); // @28@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8c24
@end

@interface PhoneCall
{
	struct __CTCall * _call; // ^{__CTCall=}
	NSString * _displayName; // @"NSString"
	NSString * _overrideName; // @"NSString"
	unsigned int _displayNameBreakPoint; // I
	int _abUid; // i
	NSString * _abLabel; // @"NSString"
	UIImage * _image; // @"UIImage"
	struct ? _phoneCallFlags; // {?="imageType"b2"abUidIsValid"b1"dialAssisted"b1}
}

- (id) smallImage; // @8@0:4
- (id) desktopImage; // @8@0:4
- (id) _image; // @8@0:4
- (void) setWasDialAssisted: (char); // v12@0:4c8
- (char) wasDialAssisted; // c8@0:4
- (void) setOverrideName: (id); // v12@0:4@8
- (id) localizedLabel; // @8@0:4
- (id) multiLineDisplayName; // @8@0:4
- (id) displayName; // @8@0:4
- (id) _displayNameWithSeparator: (id); // @12@0:4@8
- (int) abUID; // i8@0:4
- (id) number; // @8@0:4
- (void) disconnect; // v8@0:4
- (void) leaveConference; // v8@0:4
- (void) joinConference; // v8@0:4
- (char) isConferenced; // c8@0:4
- (void) unhold; // v8@0:4
- (void) hold; // v8@0:4
- (char) isVoicemail; // c8@0:4
- (char) isAlerting; // c8@0:4
- (int) status; // i8@0:4
- (struct __CTCall *) call; // ^{__CTCall=}8@0:4
- (void) _handleCallerIDChange; // v8@0:4
- (void) _handleIdentityChange; // v8@0:4
- (int) _addressBookUid; // i8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithCall: (struct __CTCall *); // @12@0:4^{__CTCall=}8
@end

@interface VoicemailMailboxController
{
	NSArray * _entries; // @"NSArray"
	VoicemailTable * _table; // @"VoicemailTable"
	NSString * _extraRowTitle; // @"NSString"
	NSMutableDictionary * _displayNameCache; // @"NSMutableDictionary"
	VoicemailPlaybackController * _playbackController; // @"VoicemailPlaybackController"
	void * _lastSelectedRecord; // ^v
	id _delegate; // @
	struct ? _mailboxControllerFlags; // {?="suspended"b1"syncingSelection"b1"unused"b30}
}

- (void) _voicemailTaskEnded: (id); // v12@0:4@8
- (void) _voicemailTaskStarted: (id); // v12@0:4@8
- (void) _addressBookChanged: (id); // v12@0:4@8
- (void) _voicemailStoreContentsRemoved: (id); // v12@0:4@8
- (void) _voicemailsAdded: (id); // v12@0:4@8
- (void) _voicemailFlagsChanged: (id); // v12@0:4@8
- (void) _filterOutEntry: (void *); // v12@0:4^v8
- (void) _filterInEntries: (id); // v12@0:4@8
- (char) entryShouldBeInList: (void *); // c12@0:4^v8
- (int) rowForVoicemailRecord: (void *); // i12@0:4^v8
- (void) _onlineStateChanged; // v8@0:4
- (void) _emptyRecordsWhileSuspended; // v8@0:4
- (void) _playStateChanged: (id); // v12@0:4@8
- (void) table: (id) disclosureClickedForRow: (int); // v16@0:4@8i12
- (void) table: (id) deleteRow: (int); // v16@0:4@8i12
- (void) performDeleteOfRecord: (void *); // v12@0:4^v8
- (void) _delayedSelectRow: (id); // v12@0:4@8
- (void) deleteSelectedRecord; // v8@0:4
- (void) _dataProgressiveLoadContinued: (id); // v12@0:4@8
- (void) _dataProgressiveLoadStarted: (id); // v12@0:4@8
- (void) _dataLoadCompleted: (id); // v12@0:4@8
- (void) tableRowSelected: (id); // v12@0:4@8
- (char) table: (id) showDisclosureForRow: (int); // c16@0:4@8i12
- (char) table: (id) disclosureClickableForRow: (int); // c16@0:4@8i12
- (id) table: (id) cellForRow: (int) column: (id) reusing: (id); // @24@0:4@8i12@16@20
- (int) numberOfRowsInTable: (id); // i12@0:4@8
- (void) selectTableRow: (int) syncingSelection: (char); // v16@0:4i8c12
- (void *) selectedRecord; // ^v8@0:4
- (void) invalidateDisplayNameEntryForSender: (id); // v12@0:4@8
- (id) displayNameForEntryAtIndex: (int); // @12@0:4i8
- (id) displayNameForRecord: (void *); // @12@0:4^v8
- (void) setPlaybackController: (id); // v12@0:4@8
- (void) setExtraRowTitle: (id); // v12@0:4@8
- (id) table; // @8@0:4
- (void) significantTimeChange; // v8@0:4
- (void) retrieveEntries; // v8@0:4
- (int) entryCount; // i8@0:4
- (void) setEntries: (id); // v12@0:4@8
- (void) setDelegate: (id); // v12@0:4@8
- (void) willBeDisplayed; // v8@0:4
- (void) resume; // v8@0:4
- (void) suspend; // v8@0:4
- (void) dealloc; // v8@0:4
- (id) initForTableWithFrame: (struct CGRect) bottomBufferHeight: (float); // @28@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8f24
- (void) performInitialization; // v8@0:4
@end

@interface OffsetAnimation
{
	struct CGPoint _startOffset; // {CGPoint="x"f"y"f}
	struct CGPoint _endOffset; // {CGPoint="x"f"y"f}
}

- (void) setProgress: (float); // v12@0:4f8
- (void) setEndOffset: (struct CGPoint); // v16@0:4{CGPoint=ff}8
- (void) setStartOffset: (struct CGPoint); // v16@0:4{CGPoint=ff}8
- (id) initWithTarget: (id); // @12@0:4@8
@end

@interface VoicemailTable
{
	UIAnimation * _offsetAnimation; // @"UIAnimation"
}

- (void) scrollRow: (int) toRect: (struct CGRect) withDuration: (float); // v32@0:4i8{CGRect={CGPoint=ff}{CGSize=ff}}12f28
- (void) setAccessoryView: (id); // v12@0:4@8
- (char) canHandleSwipes; // c8@0:4
- (char) shouldDelaySendingSelectionChanged; // c8@0:4
- (void) dealloc; // v8@0:4
@end

@interface VoicemailTrashMailboxController
{
}

- (void) clearAll; // v8@0:4
- (void) performDeleteOfRecord: (void *); // v12@0:4^v8
- (char) entryShouldBeInList: (void *); // c12@0:4^v8
- (void) retrieveEntries; // v8@0:4
@end

@interface VoicemailGreetingView
{
	UIPreferencesTable * _table; // @"UIPreferencesTable"
	VoicemailControlsView * _controlsView; // @"VoicemailControlsView"
	LevelIndicator * _levelIndicator; // @"LevelIndicator"
	int _oldGreetingType; // i
	NSString * _currentGreetingPath; // @"NSString"
	VoicemailPlaybackController * _playbackController; // @"VoicemailPlaybackController"
	AVRecorder * _recorder; // @"AVRecorder"
	NSTimer * _levelTimer; // @"NSTimer"
	id _delegate; // @
	int _lastSelectedRow; // i
	int _state; // i
	unsigned int _currentGreetingDuration; // I
	bitfield _customGreetingChanged; // b1
	bitfield _greetingLoaded; // b1
	bitfield _initializingView; // b1
}

- (char) save; // c8@0:4
- (int) _selectedGreetingType; // i8@0:4
- (void) tableSelectionDidChange: (id); // v12@0:4@8
- (void) _updateCustomCell; // v8@0:4
- (void) _configureCustomCell: (id); // v12@0:4@8
- (id) preferencesTable: (id) cellForRow: (int) inGroup: (int); // @20@0:4@8i12i16
- (int) preferencesTable: (id) numberOfRowsInGroup: (int); // i16@0:4@8i12
- (int) numberOfGroupsInPreferencesTable: (id); // i12@0:4@8
- (int) numberOfRowsInTable: (id); // i12@0:4@8
- (void) _notifyStatusMessage: (id); // v12@0:4@8
- (void) prepareForDismissal; // v8@0:4
- (void) _taskCompleted: (id); // v12@0:4@8
- (void) _save: (int); // v12@0:4i8
- (void) voicemailControlsView: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) _controlsFinishedAnimatingDown; // v8@0:4
- (void) _controlsFinishedAnimatingUp; // v8@0:4
- (void) _showCustomGreetingControls: (char) animating: (char); // v16@0:4c8c12
- (void) _greetingFetchDownloadContinued: (id); // v12@0:4@8
- (void) _greetingFetchDownloadBegan: (id); // v12@0:4@8
- (void) _greetingFetchEnded: (id); // v12@0:4@8
- (void) _stopPlaying; // v8@0:4
- (void) _stopGreetingFetchWithError: (id); // v12@0:4@8
- (void) _startPlaying; // v8@0:4
- (void) voicemailPlaybackController: (id) playbackPathDidChange: (id); // v16@0:4@8@12
- (void) _updateScrubberProgress; // v8@0:4
- (void) voicemailPlaybackController: (id) updateElapsedTime: (double) duration: (double) playableDuration: (double); // v36@0:4@8d12d20d28
- (void) _playbackStateChanged: (id); // v12@0:4@8
- (id) voicemailPlaybackControllerAudioCategory: (id); // @12@0:4@8
- (void) _stopPlayingState; // v8@0:4
- (void) _startPlayingState; // v8@0:4
- (void) _cancelRecording; // v8@0:4
- (void) _stopRecording; // v8@0:4
- (void) _removeLevelIndicator; // v8@0:4
- (void) _updateLevel; // v8@0:4
- (void) _applicationDeactivated: (id); // v12@0:4@8
- (void) _recordingStarted: (id); // v12@0:4@8
- (void) _recordingEnded: (id); // v12@0:4@8
- (void) _beginRecording; // v8@0:4
- (id) _tmpFileForRecording; // @8@0:4
- (void) _customGreetingNotRecorded; // v8@0:4
- (void) _customGreetingAlreadyRecorded; // v8@0:4
- (void) _defaultGreetingSelected; // v8@0:4
- (void) setAccessoryView: (id); // v12@0:4@8
- (void) _notifySaveAbilityChanged; // v8@0:4
- (char) canBeCancelled; // c8@0:4
- (char) canBeSaved; // c8@0:4
- (void) setPlaybackController: (id); // v12@0:4@8
- (void) setDelegate: (id); // v12@0:4@8
- (void) stop; // v8@0:4
- (void) setEnabled: (char); // v12@0:4c8
- (void) restoreStateFromDefaults; // v8@0:4
- (void) saveStateToDefaults; // v8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailGreetingTableCell
{
}

- (void) layoutSubviews; // v8@0:4
- (id) valueTextLabel; // @8@0:4
@end

@interface LevelIndicator
{
	float _level; // f
	UIView * _levelView; // @"UIView"
}

- (void) setLevel: (float); // v12@0:4f8
- (void) dealloc; // v8@0:4
- (id) initWithDefaultSize; // @8@0:4
@end

@interface AudioRouteCell
{
	char _checked; // c
}

- (void) drawBackgroundInRect: (struct CGRect) withFade: (float); // v28@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8f24
- (void) layoutSubviews; // v8@0:4
- (void) setSelected: (char) withFade: (char); // v16@0:4c8c12
- (void) setChecked: (char); // v12@0:4c8
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (id) enabledIcon; // @8@0:4
- (id) highlightedIcon; // @8@0:4
- (id) _shadowHighlightedColor; // @8@0:4
- (id) _shadowColor; // @8@0:4
@end

@interface VoicemailErrorController
{
	NSMutableArray * _currentErrors; // @"NSMutableArray"
	bitfield _dropOthers; // b1
}

- (void) systemAlertDismissed: (int) result: (int); // v16@0:4i8i12
- (void) alertSheet: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) presentErrorBlockingOthers: (id); // v12@0:4@8
- (void) presentError: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
@end

@interface AudioDeviceController
{
	id _delegate; // @
	bitfield _delegateProvidesAudioRoute; // b1
	AudioDeviceView * _deviceView; // @"AudioDeviceView"
	bitfield _reloadPending; // b1
}

- (void) _registerForAVSystemController; // v8@0:4
- (void) _updateAudioDeviceStates; // v8@0:4
- (void) _activeDeviceChanged; // v8@0:4
- (void) _audioDevicesChanged; // v8@0:4
- (void) _mediaServerDied; // v8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (id) audioDeviceView: (id) deviceAtIndex: (int) isActive: (char *); // @20@0:4@8i12^c16
- (int) audioDeviceViewNumberOfDevices: (id); // i12@0:4@8
- (void) audioDeviceView: (id) selectedItem: (int); // v16@0:4@8i12
- (void) audioDeviceView: (id) eventOccurred: (struct __GSEvent *); // v16@0:4@8^{__GSEvent=}12
- (void) selectDeviceAtIndex: (unsigned int); // v12@0:4I8
- (id) deviceNameAtIndex: (unsigned int) isActive: (char *); // @16@0:4I8^c12
- (int) activeAudioRoute; // i8@0:4
- (unsigned int) numberOfDevices; // I8@0:4
- (id) deviceViewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) monitorForAudioDevices; // v8@0:4
- (char) ambiguousAudioRoutingPossible; // c8@0:4
- (char) auxillaryAudioDevicesAvailable; // c8@0:4
- (void) dealloc; // v8@0:4
@end

@interface ButtonBackingView
{
}

- (void) drawRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (id) _buttonBackgroundImage; // @8@0:4
@end

@interface AudioTableSurroundingView
{
}

- (void) drawRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface AudioDeviceView
{
	UITable * _deviceTable; // @"UITable"
	UIView * _topBGView; // @"UIView"
	UIView * _bottomBGView; // @"UIView"
	UIView * _buttonView; // @"UIView"
	UIView * _tableView; // @"UIView"
	UIView * _subbedView; // @"UIView"
	id _delegate; // @
	char _subbedOutTable; // c
}

- (void) setDelegate: (id); // v12@0:4@8
- (void) reloadData; // v8@0:4
- (void) setActiveRow: (int); // v12@0:4i8
- (void) selectRow: (int); // v12@0:4i8
- (void) tableSelectionDidChange: (id); // v12@0:4@8
- (id) table: (id) cellForRow: (int) column: (id); // @20@0:4@8i12@16
- (int) numberOfRowsInTable: (id); // i12@0:4@8
- (void) _setupSurroundingTableViews; // v8@0:4
- (void) _takedownTable; // v8@0:4
- (void) _setupTable; // v8@0:4
- (void) showTable; // v8@0:4
- (void) suboutTable; // v8@0:4
- (void) buttonPressed: (id); // v12@0:4@8
- (void) _takedownButtons; // v8@0:4
- (void) _setupButtons; // v8@0:4
- (struct CGRect) _frameForTable; // {CGRect={CGPoint=ff}{CGSize=ff}}8@0:4
- (struct CGRect) _frameForNumDevices: (int); // {CGRect={CGPoint=ff}{CGSize=ff}}12@0:4i8
- (id) _tableFooterImage; // @8@0:4
- (id) _tableHeaderImage; // @8@0:4
- (id) _activeImage; // @8@0:4
- (id) _unselectedImage; // @8@0:4
- (id) _selectedImage; // @8@0:4
- (id) hitTest: (struct CGPoint) forEvent: (struct __GSEvent *); // @20@0:4{CGPoint=ff}8^{__GSEvent=}16
- (void) dealloc; // v8@0:4
@end

@interface AudioSelectionButton
{
	int _index; // i
}

- (void) _drawImageAndTextPartInRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (int) index; // i8@0:4
- (void) setIndex: (int); // v12@0:4i8
@end

@interface VoicemailReflectionButton
{
}

- (void) drawButtonPart: (int) inRect: (struct CGRect); // v28@0:4i8{CGRect={CGPoint=ff}{CGSize=ff}}12
- (void) sizeToFit; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailSetupPlacardCell
{
	UITextLabel * _label; // @"UITextLabel"
	VoicemailReflectionButton * _button; // @"VoicemailReflectionButton"
}

- (void) layoutSubviews; // v8@0:4
- (id) button; // @8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailSetupPlacard
{
	UIPushButton * _setupButton; // @"UIPushButton"
}

- (void) mouseUp: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
- (void) mouseDown: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
- (float) preferencesTable: (id) heightForRow: (int) inGroup: (int) withProposedHeight: (float); // f24@0:4@8i12i16f20
- (id) preferencesTable: (id) cellForRow: (int) inGroup: (int); // @20@0:4@8i12i16
- (int) preferencesTable: (id) numberOfRowsInGroup: (int); // i16@0:4@8i12
- (int) numberOfGroupsInPreferencesTable: (id); // i12@0:4@8
- (int) numberOfRowsInTable: (id); // i12@0:4@8
- (char) canSelectRow: (int); // c12@0:4i8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailSetupController
{
	UIView * _view; // @"UIView"
	UITransitionView * _transitionView; // @"UITransitionView"
	UINavigationBar * _navBar; // @"UINavigationBar"
	VoicemailPasscodeView * _passcodeView; // @"VoicemailPasscodeView"
	VoicemailGreetingView * _greetingView; // @"VoicemailGreetingView"
	VoicemailSetupGreetingStatusView * _greetingStatusView; // @"VoicemailSetupGreetingStatusView"
	VoicemailPlaybackController * _playbackController; // @"VoicemailPlaybackController"
	unsigned int _minPasswordLength; // I
	unsigned int _maxPasswordLength; // I
	NSString * _password; // @"NSString"
	id _delegate; // @
	int _stage; // i
	bitfield _saving; // b1
	bitfield _saveAttempted; // b1
}

- (void) navigationBar: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) _updateNavBarButtons; // v8@0:4
- (void) voicemailGreetingView: (id) saveErrored: (id); // v16@0:4@8@12
- (void) voicemailGreetingView: (id) statusMessageChanged: (id); // v16@0:4@8@12
- (void) voicemailGreetingViewSaveCompleted: (id); // v12@0:4@8
- (void) voicemailGreetingViewSaveAbilityChanged: (id); // v12@0:4@8
- (void) voicemailPasscodeView: (id) valueDidChange: (id); // v16@0:4@8@12
- (void) dismissSuccessfully; // v8@0:4
- (void) _taskEnded: (id); // v12@0:4@8
- (void) save; // v8@0:4
- (void) transitionFromGreeting; // v8@0:4
- (void) _showDefaultPasswordPrompt; // v8@0:4
- (void) transitionFromPasswordConfirmation; // v8@0:4
- (void) _transitionToGreeting; // v8@0:4
- (void) transitionToPasswordConfirmation; // v8@0:4
- (void) _updateParameters: (id); // v12@0:4@8
- (void) _endSetupSuccessfully: (char); // v12@0:4c8
- (char) isSaving; // c8@0:4
- (void) setPlaybackController: (id); // v12@0:4@8
- (void) setDelegate: (id); // v12@0:4@8
- (id) viewWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (void) dealloc; // v8@0:4
- (id) init; // @8@0:4
@end

@interface VoicemailPasscodeView
{
	UIView * _top; // @"UIView"
	UIPasscodeField * _field; // @"UIPasscodeField"
	UITextLabel * _prompt; // @"UITextLabel"
	UIKeyboard * _keyboard; // @"UIKeyboard"
	UIProgressIndicator * _progressIndicator; // @"UIProgressIndicator"
	int _maxLength; // i
	id _delegate; // @
}

- (char) passcodeField: (id) shouldInsertText: (id); // c16@0:4@8@12
- (void) passcodeFieldTextDidChange: (id); // v12@0:4@8
- (void) setStringValue: (id); // v12@0:4@8
- (id) stringValue; // @8@0:4
- (void) setMaxLength: (int); // v12@0:4i8
- (void) setEnabled: (char); // v12@0:4c8
- (void) setDelegate: (id); // v12@0:4@8
- (void) _promptAnimationCompleted; // v8@0:4
- (void) setPrompt: (id) showProgress: (char) animate: (int); // v20@0:4@8c12i16
- (id) _createField; // @8@0:4
- (id) _createPrompt; // @8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailGreetingEditView
{
	ProgressiveNavigationBar * _navBar; // @"ProgressiveNavigationBar"
	UIProgressIndicator * _progressIndicator; // @"UIProgressIndicator"
	VoicemailGreetingView * _greetingView; // @"VoicemailGreetingView"
	id _delegate; // @
	bitfield _dismissing; // b1
}

- (void) navigationBar: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) voicemailGreetingViewSaveCompleted: (id); // v12@0:4@8
- (void) _dismiss; // v8@0:4
- (void) voicemailGreetingViewSaveAbilityChanged: (id); // v12@0:4@8
- (void) voicemailGreetingView: (id) statusMessageChanged: (id); // v16@0:4@8@12
- (id) greetingView; // @8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailSetupGreetingStatusView
{
	UITextLabel * _textLabel; // @"UITextLabel"
	UIProgressIndicator * _progressIndicator; // @"UIProgressIndicator"
	char _showProgress; // c
}

- (void) setStatusString: (id); // v12@0:4@8
- (void) setShowProgress: (char); // v12@0:4c8
- (void) _setShowProgress: (char); // v12@0:4c8
- (void) _adjustProgressIndicatorFrame; // v8@0:4
- (char) _shouldShowProgress; // c8@0:4
- (char) _wantsToShowProgress; // c8@0:4
- (char) _isShowingProgress; // c8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithFrame: (struct CGRect); // @24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
@end

@interface VoicemailTaskMonitor
{
	int _taskType; // i
	struct __CFMachPort * _port; // ^{__CFMachPort=}
}

- (void) _taskCompleted: (id); // v12@0:4@8
- (void) _sendMessage: (int); // v16@0:4i8@12
- (void) _portInvalidated; // v8@0:4
- (void) dealloc; // v8@0:4
- (id) initWithTaskType: (int) port: (unsigned int); // @16@0:4i8I12
@end

@interface VoicemailAudioRoutingSheetButton
{
}

- (void) drawImageAtPoint: (struct CGPoint) fraction: (float); // v20@0:4{CGPoint=ff}8f16
- (void) drawTitleAtPoint: (struct CGPoint) width: (float); // v20@0:4{CGPoint=ff}8f16
@end

@interface VoicemailAudioRoutingCell
{
}

- (void) layoutSubviews; // v8@0:4
- (void) setSelected: (char) withFade: (char); // v16@0:4c8c12
@end

@interface VoicemailAudioRoutePicker
{
	id _delegate; // @
	AudioDeviceController * _audioDeviceController; // @"AudioDeviceController"
	int _manualSelection; // i
	UIView * _view; // @"UIView"
	UITable * _table; // @"UITable"
	UINavigationBar * _navBar; // @"UINavigationBar"
}

- (void) tableSelectionDidChange: (id); // v12@0:4@8
- (id) table: (id) cellForRow: (int) column: (id); // @20@0:4@8i12@16
- (int) numberOfRowsInTable: (id); // i12@0:4@8
- (void) navigationBar: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) _slideInFinished; // v8@0:4
- (void) _slideOutFinished; // v8@0:4
- (void) tearDown; // v8@0:4
- (void) reloadData; // v8@0:4
- (void) displayOnView: (id); // v12@0:4@8
- (void) dismiss; // v8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithAudioDeviceController: (id); // @12@0:4@8
@end

@interface VoicemailAudioRoutingController
{
	id _delegate; // @
	AudioDeviceController * _audioDeviceController; // @"AudioDeviceController"
	VoicemailAudioRoutePicker * _picker; // @"VoicemailAudioRoutePicker"
	char _hasAuxillaryDevices; // c
	char _isPicking; // c
}

- (void) audioDeviceControllerDeviceAvailabilityChanged: (id); // v12@0:4@8
- (char) speakerEnabledForAudioDeviceController: (id); // c12@0:4@8
- (id) activeAudioRouteForDeviceController: (id); // @12@0:4@8
- (void) audioDeviceControllerActiveRouteChanged: (id); // v12@0:4@8
- (void) audioDeviceController: (id) speakerphoneEnableRequest: (char); // v16@0:4@8c12
- (void) alertSheet: (id) buttonClicked: (int); // v16@0:4@8i12
- (void) pickerDidFinish: (id); // v12@0:4@8
- (void) activateBluetoothAudio; // v8@0:4
- (void) promptForAudioDeviceOnView: (id); // v12@0:4@8
- (char) isPicking; // c8@0:4
- (char) hasAuxillaryDevices; // c8@0:4
- (void) _applicationReactivated: (id); // v12@0:4@8
- (void) _applicationDeactivated: (id); // v12@0:4@8
- (void) suspend: (int); // v12@0:4i8
- (char) deactivateBluetoothAudio; // c8@0:4
- (void) resume; // v8@0:4
- (void) setDelegate: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithDelegate: (id); // @12@0:4@8
@end

@interface VoicemailPlacardButton
{
}

- (void) _setHighlightOnMouseDown: (char); // v12@0:4c8
- (void) _controlMouseUp: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
- (void) _controlMouseDragged: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
- (void) _controlMouseDown: (struct __GSEvent *); // v12@0:4^{__GSEvent=}8
@end

@interface VoicemailOfflineView
{
	UIPlacardButton * _callButton; // @"UIPlacardButton"
	UITextLabel * _unavailableLabel; // @"UITextLabel"
	UITextLabel * _moreWaitingLabel; // @"UITextLabel"
	id _delegate; // @
}

- (void) _callButtonClicked: (id); // v12@0:4@8
- (void) setMoreWaiting: (char); // v12@0:4c8
- (void) setDelegate: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithWidth: (float) dueToRoaming: (char); // @16@0:4f8c12
@end

@interface ProgressiveNavigationBar
{
	UIProgressIndicator * _progressIndicator; // @"UIProgressIndicator"
}

- (void) _drawPrompt: (id) inRect: (struct CGRect) withFont: (id) barStyle: (int); // v36@0:4@8{CGRect={CGPoint=ff}{CGSize=ff}}12@28i32
- (void) setPrompt: (id) showingProgress: (char); // v16@0:4@8c12
- (void) dealloc; // v8@0:4
@end

@interface PhoneDesktopView
{
	UIImage * _image; // @"UIImage"
}

- (void) drawRect: (struct CGRect); // v24@0:4{CGRect={CGPoint=ff}{CGSize=ff}}8
- (id) image; // @8@0:4
- (void) setImage: (id); // v12@0:4@8
- (void) dealloc; // v8@0:4
- (id) initWithImage: (id); // @12@0:4@8
@end

